/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:13:03 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/02/28 21:57:37 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACT_H
# define FRACT_H
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# define HEIGHT 700
# define WIDTH 700
# define MAX_ITERATION 100
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define W 13
# define A 0
# define S 1
# define D 2
# define Q 12
# define ESC 53

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_fratcol
{
    void    *mlx;
    void    *win;
    double  xmin;
    double  xmax;
    double  ymax;
    double  ymin;
    double  x;
    double  y;
    double  a;
    double  b;
    double  c_r;
    double  c_i;
    double  z_r;
    double  z_i;
    double  re_start;
    double  re_end;
    double  im_start;
    double  im_end;

    int     iteration;
    int     color;
    t_image img;
}   t_fractol;

#endif
