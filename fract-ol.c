/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:11:30 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/03/13 20:43:52 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	callmlx(t_fractol *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 800, 800, "fract-ol");
	data->img.img = mlx_new_image(data->mlx, 800, 800);
	data->img.addr = mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	data->re_start = 0;
	data->re_end = 0;
	data->im_start = 0;
	data->im_end = 0;
	data->zoom = 2;
	data->c_r = 0.285;
	data->c_i = 0;
	data->values = 100;
	data->color_code = 0;
	data->color = 0xff0801;
}

int	mouse_get_vals(int x, int y, t_fractol *data)
{
	data->c_r = ft_map(x, 800, data->re_start - data->zoom, \
	data->re_end + data->zoom);
	data->c_i = ft_map(x, 800, data->im_start - data->zoom, \
	data->im_end + data->zoom);
	ft_draw(data);
	return (0);
}

void	ft_fractol(t_fractol data)
{
	callmlx(&data);
	mlx_hook(data.win, 2, 0, set_hook, &data);
	mlx_mouse_hook (data.win, inmouse, &data);
	ft_draw(&data);
	if (data.julia)
		mlx_hook(data.win, 6, 0, mouse_get_vals, &data);
	mlx_loop(data.mlx);
}
