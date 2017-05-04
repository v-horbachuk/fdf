/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:22:55 by vhorbach          #+#    #+#             */
/*   Updated: 2017/04/11 15:05:35 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void		draw_pixel(int x, int y, t_print *p, t_all *all)
{
	int		a;

	a = (4 * (y * IMG_WID + x));
	if (x < 0 || x >= WIN_WID || y < 0 || y >= WIN_HIGH)
		return ;
	all->mlx.gda[a] = (char)p->colour.c_b;
	all->mlx.gda[a + 1] = (char)p->colour.c_g;
	all->mlx.gda[a + 2] = (char)p->colour.c_r;
	all->mlx.gda[a + 3] = (char)p->colour.opacity;
}

void		brezen(t_print *p, t_all *all)
{
	int		x;
	int		y;
	double	dx;
	double	dy;
	double	error;

	dy = fabs(p->y1 - p->y0);
	dx = fabs(p->x1 - p->x0);
	error = 0;
	y = (int)p->y0;
	x = (int)p->x0 - 1;
	while (++x < p->x1)
	{
		if (p->swapped == 1)
			draw_pixel(y, x, p, all);
		else
			draw_pixel(x, y, p, all);
		error = error + dy;
		if (2 * error >= dx)
		{
			y += p->y_direction;
			error = error - dx;
		}
	}
}

void		draw_x(t_all *all)
{
	t_cords	*temp;
	int		i;
	int		j;

	temp = all->map;
	i = -1;
	while (++i < all->max.max_y)
	{
		j = -1;
		while (++j < all->max.max_x - 1)
		{
			{
				all->p.x0 = temp->x1;
				all->p.y0 = temp->y1;
				all->p.x1 = temp->next->x1;
				all->p.y1 = temp->next->y1;
				all->p.z = temp->z;
				all->p.colour = temp->colour;
				check_octant(all->p, all);
			}
			temp = temp->next;
		}
		temp = temp->next;
	}
}

void		draw_y(t_all *all)
{
	t_cords	*temp;
	t_cords	*current;

	temp = all->map;
	current = temp->next;
	while (current->next)
	{
		while (current->x != temp->x)
			current = current->next;
		all->p.x0 = temp->x1;
		all->p.y0 = temp->y1;
		all->p.x1 = current->x1;
		all->p.y1 = current->y1;
		all->p.z = temp->z;
		all->p.colour = temp->colour;
		check_octant(all->p, all);
		temp = temp->next;
	}
}

void		ft_image(t_all *all)
{
	all->mlx.img = mlx_new_image(all->mlx.mlx, IMG_WID, IMG_HIGH);
	all->mlx.gda = mlx_get_data_addr(all->mlx.img, &all->mlx.bpp,
					&all->mlx.sl, &all->mlx.endian);
	draw_x(all);
	draw_y(all);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
	mlx_string_put(all->mlx.mlx, all->mlx.win, 20, 20, 0x00ff00, "USAGE:");
	mlx_string_put(all->mlx.mlx, all->mlx.win, 20, 75,
					0x00ff00, "Move: arrows, page_up/down");
	mlx_string_put(all->mlx.mlx, all->mlx.win, 20, 95,
					0x00ff00, "Zoom: +, -");
	mlx_string_put(all->mlx.mlx, all->mlx.win, 20, 115,
					0x00ff00, "Rotate: x_axis: A-D, y_axis: W-S, z_axis: Q-E");
	mlx_string_put(all->mlx.mlx, all->mlx.win, 20,
					135, 0x00ff00, "Change colour: blue: num 1-3, "
					"green: num 4-6, red: num 7-9");
	mlx_destroy_image(all->mlx.mlx, all->mlx.img);
}
