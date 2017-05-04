/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:47:58 by vhorbach          #+#    #+#             */
/*   Updated: 2017/04/08 17:48:03 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void	ft_change_blue(t_all *all, double param)
{
	t_cords *temp;

	temp = all->map;
	if (param == 1 || param == -1)
	{
		while (temp)
		{
			if (temp->colour.c_b >= 255)
				temp->colour.c_b -= param;
			else if (temp->colour.c_b <= 0)
				temp->colour.c_b -= param;
			else
				temp->colour.c_b += param;
			temp = temp->next;
		}
		ft_image(all);
	}
}

void	ft_change_green(t_all *all, double param)
{
	t_cords *temp;

	temp = all->map;
	if (param == 2 || param == -2)
	{
		while (temp)
		{
			if (temp->colour.c_g >= 255)
				temp->colour.c_g -= param / 2;
			else if (temp->colour.c_g <= 0)
				temp->colour.c_g -= param / 2;
			else
				temp->colour.c_g += param / 2;
			temp = temp->next;
		}
		ft_image(all);
	}
}

void	ft_change_red(t_all *all, double param)
{
	t_cords *temp;

	temp = all->map;
	if (param == 3 || param == -3)
	{
		while (temp)
		{
			if (temp->colour.c_r >= 255)
				temp->colour.c_r -= param / 3;
			else if (temp->colour.c_r <= 0)
				temp->colour.c_r -= param / 3;
			else
				temp->colour.c_r += param / 3;
			temp = temp->next;
		}
		ft_image(all);
	}
}

void	ft_change_opacity(t_all *all, double param)
{
	t_cords *temp;

	temp = all->map;
	if (param == 5 || param == -5)
	{
		while (temp)
		{
			if (temp->colour.opacity > 255 || temp->colour.opacity < 0)
				break ;
			temp->colour.opacity += param;
			temp = temp->next;
		}
		ft_image(all);
	}
}

void	ft_std_colour(t_all *all, double param)
{
	t_cords *temp;

	temp = all->map;
	if (param == 0)
	{
		while (temp)
		{
			temp->colour = temp->std_colour;
			temp = temp->next;
		}
		all->m.result = all->m.result_space;
		ft_change_units(all->m.result, all);
	}
}
