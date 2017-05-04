/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:19:49 by vhorbach          #+#    #+#             */
/*   Updated: 2017/04/15 17:32:28 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void		mlx_define(t_all *all)
{
	all->mlx.mlx = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.mlx, WIN_WID, WIN_HIGH, "FDF");
	ft_matr_init_1(all);
	ft_image(all);
	mlx_hook(all->mlx.win, 2, 3, key_hook, all);
	mlx_loop(all->mlx.mlx);
}

t_cords		*remove_null(t_all *all)
{
	t_cords	*temp;

	temp = all->map;
	while (temp)
	{
		temp->x = temp->x - (double)all->max.max_x / 2.;
		temp->y = temp->y - (double)all->max.max_y / 2.;
		temp->std_colour = temp->colour;
		temp = temp->next;
	}
	temp = all->map;
	while (temp->next->next)
		temp = temp->next;
	free(temp->next->next);
	temp->next = NULL;
	return (all->map);
}

t_cords		*ft_search_cords(char *line, int y, t_all *all, t_cords *map)
{
	t_cords	*temp;
	char	**arr;
	int		c;

	temp = map;
	all->max.max_x = 0;
	arr = ft_strsplit(line, ' ');
	while (arr[all->max.max_x])
	{
		temp->y = y;
		temp->x = all->max.max_x;
		temp->z = ft_atoi(arr[all->max.max_x]);
		if (temp->z > all->max.max_z)
			all->max.max_z = (int)temp->z;
		else if (temp->z < all->max.min_z)
			all->max.min_z = (int)temp->z;
		temp->next = malloc(sizeof(t_cords));
		if ((c = read_colour(arr[all->max.max_x])))
			temp->colour = ft_disperse(all, c);
		else
			temp->colour = ft_disperse(all, 0xffffff);
		temp = temp->next;
		all->max.max_x++;
	}
	return (temp);
}

t_cords		*read_fdf(int fd, t_all *all)
{
	t_cords	*temp;
	char	*line;

	all->max.max_y = 0;
	all->max.max_z = 0;
	all->max.min_z = 0;
	line = NULL;
	temp = all->map;
	if (!(get_next_line(fd, &line)))
	{
		write(1, "File is empty\n", 14);
		exit(1);
	}
	while (get_next_line(fd, &line))
	{
		temp = ft_search_cords(line, all->max.max_y, all, temp);
		all->max.max_y++;
	}
	all->map = remove_null(all);
	return (all->map);
}

int			main(int ac, char **av)
{
	int		fd;
	t_all	*all;

	if (ac == 2)
	{
		all = (t_all*)malloc(sizeof(t_all));
		all->map = (t_cords*)malloc(sizeof(t_cords));
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			write(1, "File doesn't exist\n", 19);
			exit(1);
		}
		all->map = read_fdf(fd, all);
		mlx_define(all);
		close(fd);
	}
	else
		write(1, "usage: Please, use just ONE argument"
					"for executable 'fdf'\n", 58);
	return (0);
}
