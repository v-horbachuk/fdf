/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fuct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 20:55:06 by vhorbach          #+#    #+#             */
/*   Updated: 2017/04/10 20:55:09 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

t_colour	ft_disperse(t_all *all, int paint)
{
	all->map->colour.c_b = paint % 256;
	all->map->colour.c_g = (paint >> 8) % 256;
	all->map->colour.c_r = paint >> 16;
	all->map->colour.opacity = paint >> 24;
	return (all->map->colour);
}

int			read_colour(char *str)
{
	int		i;
	int		j;
	int		nb;
	char	*str1;

	i = 0;
	j = 0;
	str1 = (char *)malloc(sizeof(char) * 7);
	while (str[i])
	{
		if (str[i] == 'x')
			break ;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[++i])
	{
		str1[j] = str[i];
		j++;
	}
	nb = ft_atoi_base(str1, 16);
	free(str1);
	return (nb);
}

void		swap_cords(t_print *p)
{
	double	a;

	a = p->x0;
	p->x0 = p->y0;
	p->y0 = a;
	a = p->x1;
	p->x1 = p->y1;
	p->y1 = a;
}

void		swap_points(t_print *p)
{
	double	x;
	double	y;

	y = p->y0;
	x = p->x0;
	p->x0 = p->x1;
	p->x1 = x;
	p->y0 = p->y1;
	p->y1 = y;
}

void		check_octant(t_print p, t_all *all)
{
	double	dx;
	double	dy;

	dx = fabs(p.x1 - p.x0);
	dy = fabs(p.y1 - p.y0);
	p.y_direction = 1;
	if (dy > dx)
	{
		swap_cords(&p);
		p.swapped = 1;
	}
	if (p.x1 < p.x0)
		swap_points(&p);
	if (p.y1 < p.y0)
		p.y_direction = -1;
	brezen(&p, all);
}
