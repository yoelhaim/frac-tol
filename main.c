/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:59:20 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/03/13 20:45:25 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#include <string.h>

int	main(int ac, char **av)
{
	t_fractol	data;

	data.julia = 0;
	if (ac == 2)
	{
		if (!strcmp(av[1], "1"))
			data.julia = 0;
		else if (!strcmp(av[1], "2"))
			data.julia = 1;
		else if (!strcmp(av[1], "3"))
		{
			data.burning_ship = 1;
			data.julia = 0;
		}
		else
		{
			fractols();
			exit(1);
		}
		controls();
		ft_fractol(data);
	}
	else
		fractols();
}
