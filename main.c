/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:59:20 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/03/14 16:21:39 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	ft_strcmp(char *s, char *s2)
{
	int	i;

	i = 0;
	if (!s && s2)
		return (0);
	while (s[i] && s2[i] && s[i] == s2[i])
		i++;
	return (s2[i] - s[i]);
}

int	main(int ac, char **av)
{
	t_fractol	data;

	data.julia = 0;
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "1"))
			data.julia = 0;
		else if (!ft_strcmp(av[1], "2"))
			data.julia = 1;
		else if (!ft_strcmp(av[1], "3"))
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
