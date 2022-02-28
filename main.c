/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:11:30 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/02/28 22:25:27 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

double    ft_map(int in, double in_end, double out_start, double out_end)
{
    double    val;

    val = out_start + ((out_end - out_start) / in_end) * in;
    return (val);
}

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void    ft_draw(t_fractol *data)
{
    mlx_clear_window(data->mlx, data->win);
    data->x = 0;
    while (data->x < 800)
    {
        data->y = 0;
        while (data->y < 800)
        {
            data->a = ft_map(data->x, 800, data->re_start, data->re_end);
            data->b = ft_map(data->y, 800, data->im_start, data->im_end);
            data->c_r = data->a;
            data->c_i = data->b;
            data->iteration = 0;
            while (data->iteration < MAX_ITERATION)
            {
                data->z_r = data->a * data->a - data->b * data->b;
                data->z_i = data->a * data->b * 2;
                data->a = data->z_r + data->c_r;
                data->b = data->z_i + data->c_i;
                data->iteration++;
                if (data->a * data ->a + data->b *data->b > 4)
                    break ;
            }
            data->color = 0;
            if (data->iteration < MAX_ITERATION)
                data->color = data->iteration * 0xff0801;
            my_mlx_pixel_put(data, data->x, data->y, data->color);
            data->y++;
        }
        data->x++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
void ft_moves(int key, t_fractol *data)
{
    if (key == UP)
    {
        data->im_start +=0.09;
        data->im_end +=0.09;
    }
    if (key == RIGHT)
    {
        data->re_start -=0.09;
        data->re_end -=0.09;
    }
    if (key == DOWN)
    {
        data->im_start -=0.09;
        data->im_end -=0.09;
    }
    if (key == LEFT)
    {
        data->re_start +=0.09;
        data->re_end +=0.09;
    }
        ft_draw(data);
}
int set_hook(int keyh, t_fractol *data)
{
	if (keyh == LEFT || keyh == RIGHT || keyh == UP || keyh == DOWN)
		 ft_moves(keyh, data);
	if (keyh == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(1);
	}
	ft_draw(data);
	return 0;
}

int main()
{
	t_fractol data;

	data.re_start = -2;
    data.re_end = 2;
    data.im_start = -2;
    data.im_end = 2;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 800, 800, "fract-ol");
	data.img.img = mlx_new_image(data.mlx, 800, 800);
    data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
    ft_draw(&data);
	mlx_hook(data.win, 2, 0, set_hook, &data);
	mlx_loop(data.mlx);
}
