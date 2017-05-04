/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:14:11 by vhorbach          #+#    #+#             */
/*   Updated: 2017/04/05 19:14:14 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

t_matr		*ft_matr_create(void)
{
	int		i;
	int		j;
	t_matr	*m;

	i = 0;
	m = (t_matr *)malloc(sizeof(t_matr));
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m->matr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (m);
}

t_matr		*matr_mult(t_matr *m1, t_matr *m2)
{
	int		i;
	int		j;
	int		k;
	double	sum;
	t_matr	*m3;

	i = -1;
	m3 = (t_matr *)malloc(sizeof(t_matr));
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			sum = 0;
			k = 0;
			while (k++ < 4)
				sum += m1->matr[i][k - 1] * m2->matr[k - 1][j];
			m3->matr[i][j] = sum;
		}
	}
	return (m3);
}

void		ft_matr_init_2(t_all *all)
{
	ft_trans_init(all->max.max_x / 2. + 0.5, all->max.max_y / 2. + 0.5, 0, all);
	all->m.result = *matr_mult(&all->m.result, &all->m.trans);
	ft_scale_init(.5, .5, .5, all);
	all->m.result = *matr_mult(&all->m.result, &all->m.scale);
	ft_rot_x_init(0., all);
	all->m.result = *matr_mult(&all->m.result, &all->m.x_rot);
	ft_rot_y_init(0., all);
	all->m.result = *matr_mult(&all->m.result, &all->m.y_rot);
	ft_rot_z_init(0., all);
	all->m.result = *matr_mult(&all->m.result, &all->m.z_rot);
	all->m.result_space = all->m.result;
	ft_change_units(all->m.result, all);
}

void		ft_matr_init_1(t_all *all)
{
	all->m.vp = *ft_matr_create();
	all->m.vp.matr[0][0] = WIN_WID / 2.;
	all->m.vp.matr[0][3] = (WIN_WID - 1) / 2.;
	all->m.vp.matr[1][1] = WIN_HIGH / 2.;
	all->m.vp.matr[1][3] = (WIN_HIGH - 1) / 2.;
	all->m.vp.matr[2][2] = 1;
	all->m.vp.matr[3][3] = 1;
	all->m.orth = *ft_matr_create();
	all->m.orth.matr[0][0] = 2. / all->max.max_x;
	all->m.orth.matr[0][3] = -1;
	all->m.orth.matr[1][1] = 2. / all->max.max_y;
	all->m.orth.matr[1][3] = -1;
	all->m.orth.matr[2][2] = 2. / (all->max.max_z - all->max.min_z + 1);
	all->m.orth.matr[2][3] = -(double)(abs(all->max.max_z) +
			abs(all->max.min_z)) / (double)(abs(all->max.max_z) -
			abs(all->max.min_z) + 1);
	all->m.orth.matr[3][3] = 1;
	all->m.result = *matr_mult(&all->m.vp, &all->m.orth);
	ft_matr_init_2(all);
}
