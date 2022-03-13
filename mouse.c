/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:37:47 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/03/13 16:57:04 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	inmouse(int keyhok, int x, int y, t_fractol *data)
{
	double	a_x;
	double	a_y;
	double	b_x;
	double	b_y;

	b_x = ft_map(x, 800, data->re_start - data->zoom, \
	data->re_end + data->zoom);
	b_y = ft_map(y, 800, data->im_start - data->zoom, \
	data->im_end + data->zoom);
	if (keyhok == 5)
		data->zoom /= 1.1;
	if (keyhok == 4)
		data->zoom *= 1.1;
	a_x = ft_map(x, 800, data->re_start - data->zoom, \
	data->re_end + data->zoom);
	a_y = ft_map(y, 800, data->im_start - data->zoom, \
	data->im_end + data->zoom);
	data->re_start += (b_x - a_x);
	data->re_end += (b_x - a_x);
	data-> im_start += (b_y - a_y);
	data->im_end += (b_y - a_y);
	ft_draw(data);
	return (0);
}

void	ft_get_color(t_fractol *data)
{
	data->color_code++;
	if (data->color_code == 8)
		data->color_code = 0;
	if (data->color_code == 0)
		data->color = 0xff0801;
	else if (data->color_code == 1)
		data->color = 0xfff600;
	else if (data->color_code == 2)
		data->color = 0x18ff00;
	else if (data->color_code == 3)
		data->color = 0xf4f4f5;
	else if (data->color_code == 4)
		data->color = 0xb0ffd9;
	else if (data->color_code == 5)
		data->color = 0xffffd9;
	else if (data->color_code == 6)
		data->color = 0xFFFCA7;
	else if (data->color_code == 7)
		data->color = 0xf1f1e1;
}
