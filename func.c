/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:23:22 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/03/13 22:09:19 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

double	ft_map(int in, double in_end, double out_start, double out_end)
{
	return (out_start + ((out_end - out_start) / in_end) * in);
}

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length + x \
	* (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_mapped(t_fractol *data)
{
	data->a = ft_map(data->x, 800, data->real_start - data->zoom,
			data->real_end + data->zoom);
	data->b = ft_map(data->y, 800, data->imagin_start - data->zoom,
			data->imagin_end + data->zoom);
	if (!data->julia)
	{
		data->c_real = data->a;
		data->c_imagin = data->b;
	}
}

void	ft_moves(int key, t_fractol *data)
{
	if (key == UP)
	{
		data->imagin_start += 0.1 * data->zoom;
		data->imagin_end += 0.1 * data->zoom;
	}
	if (key == RIGHT)
	{
		data->real_start -= 0.1 * data->zoom;
		data->real_end -= 0.1 * data->zoom;
	}
	if (key == DOWN)
	{
		data->imagin_start -= 0.1 * data->zoom;
		data->imagin_end -= 0.1 * data->zoom;
	}
	if (key == LEFT)
	{
		data->real_start += 0.1 * data->zoom;
		data->real_end += 0.1 * data->zoom;
	}
	ft_draw(data);
}

int	set_hook(int keyh, t_fractol *data)
{
	if (keyh == LEFT || keyh == RIGHT || keyh == UP || keyh == DOWN)
		ft_moves(keyh, data);
	if (keyh == 8)
		ft_get_color(data);
	if (keyh == ESC || keyh == QUIT)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(1);
	}
	ft_draw(data);
	return (0);
}
