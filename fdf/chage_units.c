/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chage_units.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:52:26 by vhorbach          #+#    #+#             */
/*   Updated: 2017/04/04 11:52:28 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void	ft_change_units(t_matr m, t_all *all)
{
	int		i;
	t_cords	*temp;

	temp = all->map;
	while (temp)
	{
		i = 0;
		temp->x1 = m.matr[i][0] * temp->x + m.matr[i][1] * temp->y +
				m.matr[i][2] * temp->z + m.matr[i][3];
		i++;
		temp->y1 = m.matr[i][0] * temp->x + m.matr[i][1] * temp->y +
				m.matr[i][2] * temp->z + m.matr[i][3];
		temp = temp->next;
	}
	ft_image(all);
}

void	rot_xyz(t_all *all, double param)
{
	if (param == 2 || param == -2)
	{
		ft_rot_x_init(param, all);
		all->m.result = *matr_mult(&all->m.result, &all->m.x_rot);
	}
	else if (param == 4 || param == -4)
	{
		ft_rot_y_init(param / 2, all);
		all->m.result = *matr_mult(&all->m.result, &all->m.y_rot);
	}
	else if (param == 6 || param == -6)
	{
		ft_rot_z_init(param / 3, all);
		all->m.result = *matr_mult(&all->m.result, &all->m.z_rot);
	}
	ft_change_units(all->m.result, all);
}

void	move_xyz(t_all *all, double param)
{
	if (param == 1 || param == -1)
	{
		ft_trans_init(param, 0, 0, all);
		all->m.result = *matr_mult(&all->m.result, &all->m.trans);
	}
	else if (param == 2 || param == -2)
	{
		ft_trans_init(0, param / 2, 0, all);
		all->m.result = *matr_mult(&all->m.result, &all->m.trans);
	}
	else if (param == 3 || param == -3)
	{
		ft_trans_init(0, 0, param / 3, all);
		all->m.result = *matr_mult(&all->m.result, &all->m.trans);
	}
	else if (param == 4 || param == .85)
	{
		if (param == 4)
			param = 1.15;
		ft_scale_init(param, param, param, all);
		all->m.result = *matr_mult(&all->m.result, &all->m.scale);
	}
	ft_change_units(all->m.result, all);
}
