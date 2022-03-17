/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:11:30 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/03/14 16:25:51 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	callmlx(t_fractol *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fract-ol");
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	data->real_start = 0;
	data->real_end = 0;
	data->imagin_start = 0;
	data->imagin_end = 0;
	data->zoom = 2;
	data->c_real = 0.285;
	data->c_imagin = 0;
	data->values = 100;
	data->color_code = 0;
	data->color = 0x1A40DC;
	data->julia_set = 0;
}

int	destroywindwo(t_fractol *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(1);
}

int	mouse_get_vals(int x, int y, t_fractol *data)
{
	if (data->julia_set)
	{
		data->c_real = ft_map(x, WIDTH, data->real_start - data->zoom, \
	data->real_end + data->zoom);
	data->c_imagin = ft_map(y, HEIGHT, data->imagin_start - data->zoom, \
	data->imagin_end + data->zoom);
	}
	ft_draw(data);
	return (0);
}

void	ft_fractol(t_fractol data)
{
	callmlx(&data);
	mlx_hook(data.win, 2, 0, set_hook, &data);
	mlx_mouse_hook (data.win, inmouse, &data);
	mlx_hook(data.win, 17, 0, destroywindwo, &data);
	ft_draw(&data);
	if (data.julia)
	{
		data.julia_set = 1;
		mlx_hook(data.win, 6, 0, mouse_get_vals, &data);
	}
	mlx_loop(data.mlx);
}
