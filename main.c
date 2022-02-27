/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:11:30 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/02/27 22:57:34 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int set_hook(int keyh, t_fract *data)
{
	if (keyh == LEFT)
		printf("left\n");
	if (keyh == RIGHT)
		printf("right\n");
	if (keyh == UP)
		printf("up\n");
	if (keyh == DOWN)
		printf("down\n");
	if (keyh == ESC)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(1);
	}
	return 0;
}

int main()
{
	t_fract data;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 800, 800, "fract-ol");
	mlx_hook(data.mlx_win, 2, 0, set_hook, &data);
	mlx_loop(data.mlx);
}
