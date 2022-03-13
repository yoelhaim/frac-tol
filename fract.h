/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:49:05 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/03/13 20:44:04 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define HEIGHT 700
# define WIDTH 700
# define MAX_ITERATION 100
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define QUIT 12
# define W 13
# define A 0
# define S 1
# define D 2
# define Q 12
# define ESC 53
# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_fratcol
{
	void	*mlx;
	void	*win;
	double	xmin;
	double	xmax;
	double	ymax;
	double	ymin;
	double	x;
	double	y;
	double	a;
	double	b;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	re_start;
	double	re_end;
	double	im_start;
	double	im_end;
	double	values;
	double	zoom;
	int		color_code;
	int		iteration;
	int		color;
	int		julia;
	int		julia_bool;
	int		burning_ship;
	t_image	img;
}	t_fractol;

double	ft_map(int in, double in_end, double out_start, double out_end);
void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
void	ft_draw(t_fractol *data);
void	ft_moves(int key, t_fractol *data);
int		set_hook(int keyh, t_fractol *data);
int		inmouse(int keyhok, int x, int y, t_fractol *data);
void	mandelbrot(t_fractol *data);
void	ft_mapped(t_fractol *data);
void	ft_get_color(t_fractol *data);
void	ft_fractol(t_fractol data);
void	printf_help(void);
void	fractols(void);
void	controls(void);
int		mouse_get_vals(int x, int y, t_fractol *data);
#endif
