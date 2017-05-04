/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:11:02 by vhorbach          #+#    #+#             */
/*   Updated: 2017/04/15 17:11:03 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIREFRAME_H
# define WIREFRAME_H
# define WIN_WID 1200
# define WIN_HIGH 900
# define IMG_WID 1200
# define IMG_HIGH 900
# define PI 3.14159265358979323846

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <math.h>
# include "libft/libft.h"
# include <mlx.h>
# include <stdio.h>

typedef	struct			s_max
{
	int					max_x;
	int					max_y;
	int					max_z;
	int					min_z;
}						t_max;

typedef	struct			s_colour
{
	int					c_b;
	int					c_g;
	int					c_r;
	int					opacity;
}						t_colour;

typedef	struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*gda;
	int					bpp;
	int					sl;
	int					endian;
}						t_mlx;

typedef	struct			s_print
{
	double				x0;
	double				y0;
	double				x1;
	double				y1;
	double				z;
	int					swapped;
	int					y_direction;
	t_colour			colour;
}						t_print;

typedef	struct			s_cords
{
	struct s_cords		*next;
	double				x;
	double				y;
	double				z;
	double				x1;
	double				y1;
	t_colour			colour;
	t_colour			std_colour;
}						t_cords;

typedef	struct			s_matr
{
	double				matr[4][4];
}						t_matr;

typedef struct			s_matrix
{
	t_matr				vp;
	t_matr				orth;
	t_matr				trans;
	t_matr				scale;
	t_matr				x_rot;
	t_matr				y_rot;
	t_matr				z_rot;
	t_matr				result;
	t_matr				result_space;
}						t_matrix;

typedef struct			s_all
{
	t_matrix			m;
	t_mlx				mlx;
	t_max				max;
	t_print				p;
	t_cords				*map;
}						t_all;

int						read_colour(char *str);
int						ft_atoi_base(char *str, int str_base);
int						key_rotation(int keycode, t_all *all);
int						key_colour(int keycode, t_all *all);
int						key_hook(int keycode, t_all *all);
void					ft_draw(int a, t_cords *map, t_all *all);
void					ft_image(t_all *all);
void					ft_change_blue(t_all *all, double param);
void					ft_change_green(t_all *all, double param);
void					ft_change_red(t_all *all, double param);
void					ft_change_opacity(t_all *all, double param);
void					ft_std_colour(t_all *all, double param);
void					ft_change_units(t_matr m, t_all *all);
void					move_xyz(t_all *all, double param);
void					ft_matr_init_1(t_all *all);
void					ft_matr_init_2(t_all *all);
t_matr					*ft_matr_create(void);
t_matr					*matr_mult(t_matr *m1, t_matr *m2);
void					ft_trans_init(double x, double y, double z, t_all *all);
void					ft_scale_init(double x, double y, double z, t_all *all);
void					ft_rot_x_init(double deg, t_all *all);
void					ft_rot_y_init(double deg, t_all *all);
void					ft_rot_z_init(double deg, t_all *all);
void					rot_xyz(t_all *all, double param);
t_colour				ft_disperse(t_all *all, int	paint);
void					check_octant(t_print p, t_all *all);
void					brezen(t_print *p, t_all *all);

#endif
