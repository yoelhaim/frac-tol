/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:54:00 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/03/13 19:54:00 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	mandelbrot(t_fractol *data)
{
	while (data->iteration < data->values)
	{
		data->z_r = data->a * data->a - data->b * data->b;
		data->z_i = data->a * data->b * 2;
		if (data->burning_ship)
			data->z_i = fabs(data->a * data->b * 2);
		data->a = data->z_r + data->c_r;
		data->b = data->z_i + data->c_i;
		data->iteration++;
		if (data->a * data ->a + data->b * data->b > 4)
			break ;
	}
}

void	ft_draw(t_fractol *data)
{
	int	color;

	mlx_clear_window (data->mlx, data->win);
	data->x = 0;
	while (data->x < 800)
	{
		data->y = 0;
		while (data->y < 800)
		{
			ft_mapped (data);
			data->iteration = 0;
			mandelbrot(data);
			color = 0;
			if (data->iteration < data->values)
				color = data->iteration * data->color;
			my_mlx_pixel_put(data, data->x, data->y, color);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
