/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 21:07:52 by vhorbach          #+#    #+#             */
/*   Updated: 2017/04/10 21:07:54 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void		ft_trans_init(double x, double y, double z, t_all *all)
{
	all->m.trans = *ft_matr_create();
	all->m.trans.matr[0][0] = 1;
	all->m.trans.matr[1][1] = 1;
	all->m.trans.matr[2][2] = 1;
	all->m.trans.matr[3][3] = 1;
	all->m.trans.matr[0][3] = x;
	all->m.trans.matr[1][3] = y;
	all->m.trans.matr[2][3] = z;
}

void		ft_scale_init(double x, double y, double z, t_all *all)
{
	all->m.scale = *ft_matr_create();
	all->m.scale.matr[0][0] = x;
	all->m.scale.matr[1][1] = y;
	all->m.scale.matr[2][2] = z;
	all->m.scale.matr[3][3] = 1;
}

void		ft_rot_x_init(double deg, t_all *all)
{
	double	rad;

	rad = PI * deg / 180;
	all->m.x_rot = *ft_matr_create();
	all->m.x_rot.matr[0][0] = 1;
	all->m.x_rot.matr[1][1] = cos(rad);
	all->m.x_rot.matr[1][2] = -sin(rad);
	all->m.x_rot.matr[2][1] = sin(rad);
	all->m.x_rot.matr[2][2] = cos(rad);
	all->m.x_rot.matr[3][3] = 1;
}

void		ft_rot_y_init(double deg, t_all *all)
{
	double	rad;

	rad = PI * deg / 180;
	all->m.y_rot = *ft_matr_create();
	all->m.y_rot.matr[0][0] = cos(rad);
	all->m.y_rot.matr[0][2] = sin(rad);
	all->m.y_rot.matr[1][1] = 1;
	all->m.y_rot.matr[2][0] = -sin(rad);
	all->m.y_rot.matr[2][2] = cos(rad);
	all->m.y_rot.matr[3][3] = 1;
}

void		ft_rot_z_init(double deg, t_all *all)
{
	double	rad;

	rad = PI * deg / 180;
	all->m.z_rot = *ft_matr_create();
	all->m.z_rot.matr[0][0] = cos(rad);
	all->m.z_rot.matr[0][1] = -sin(rad);
	all->m.z_rot.matr[1][0] = sin(rad);
	all->m.z_rot.matr[1][1] = cos(rad);
	all->m.z_rot.matr[2][2] = 1;
	all->m.z_rot.matr[3][3] = 1;
}
