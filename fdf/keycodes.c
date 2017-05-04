/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:00:49 by vhorbach          #+#    #+#             */
/*   Updated: 2017/04/10 19:00:53 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

int		key_rotation(int keycode, t_all *all)
{
	if (keycode == 2)
		rot_xyz(all, 2);
	else if (keycode == 0)
		rot_xyz(all, -2);
	else if (keycode == 13)
		rot_xyz(all, 4);
	else if (keycode == 1)
		rot_xyz(all, -4);
	else if (keycode == 14)
		rot_xyz(all, 6);
	else if (keycode == 12)
		rot_xyz(all, -6);
	return (0);
}

int		key_colour(int keycode, t_all *all)
{
	if (keycode == 85)
		ft_change_blue(all, 1);
	else if (keycode == 83)
		ft_change_blue(all, -1);
	else if (keycode == 88)
		ft_change_green(all, 2);
	else if (keycode == 86)
		ft_change_green(all, -2);
	else if (keycode == 92)
		ft_change_red(all, 3);
	else if (keycode == 89)
		ft_change_red(all, -3);
	else if (keycode == 65)
		ft_change_opacity(all, 5);
	else if (keycode == 82)
		ft_change_opacity(all, -5);
	else
		key_rotation(keycode, all);
	return (0);
}

int		key_hook(int keycode, t_all *all)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 49)
		ft_std_colour(all, 0);
	else if (keycode == 124)
		move_xyz(all, 1);
	else if (keycode == 123)
		move_xyz(all, -1);
	else if (keycode == 126)
		move_xyz(all, -2);
	else if (keycode == 125)
		move_xyz(all, 2);
	else if (keycode == 116)
		move_xyz(all, -3);
	else if (keycode == 121)
		move_xyz(all, 3);
	else if (keycode == 24 || keycode == 69)
		move_xyz(all, 4);
	else if (keycode == 27 || keycode == 78)
		move_xyz(all, .85);
	else
		key_colour(keycode, all);
	return (0);
}
