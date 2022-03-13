/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:05:33 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/03/13 20:45:14 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	printf_help(void)
{
	write(1, ANSI_COLOR_GREEN"------------------------------------ \n", 44);
	write(1, ANSI_COLOR_RED"----Arrow RIGHT--------- > OR D ---- \n", 44);
	write(1, ANSI_COLOR_RED"---- Arrow Left--------- < OR A ---- \n", 44);
	write(1, ANSI_COLOR_RED"---- Arrow TOP--------- ^ OR W ---- \n", 44);
	write(1, ANSI_COLOR_RED"---- Arrow RIGHT--------- w OR Z --- \n", 44);
	write(1, ANSI_COLOR_GREEN"------------------------------------ \n", 44);
}

void	fractols(void)
{
	write(1, ANSI_COLOR_GREEN"~ FRACT'OLS \n", 53);
	write(1, ANSI_COLOR_GREEN"                                        \n", 53);
	write(1, ANSI_COLOR_GREEN"     1- Mandelbrot                      \n", 53);
	write(1, ANSI_COLOR_GREEN"     2- Julia                           \n", 53);
	write(1, ANSI_COLOR_GREEN"     3- Burning Ship                    \n", 53);
	write(1, ANSI_COLOR_GREEN"                                        \n", 53);
	write(1, ANSI_COLOR_GREEN"~~\n", 53);
}

void	controls(void)
{
	write(1, ANSI_COLOR_GREEN"~~~~~~~~~~~~~~~CONTROLS ~~~~~~~~~~~~~~~\n", 46);
	write(1, ANSI_COLOR_GREEN"                                       \n", 47);
	write(1, ANSI_COLOR_GREEN"    ↑           : Move Up              \n", 48);
	write(1, ANSI_COLOR_GREEN"    →           : Move Right           \n", 48);
	write(1, ANSI_COLOR_GREEN"    ↓           : Move Down            \n", 48);
	write(1, ANSI_COLOR_GREEN"    ←           : Move Left            \n", 48);
	write(1, ANSI_COLOR_GREEN"    +, P        : Increase Iteration   \n", 46);
	write(1, ANSI_COLOR_GREEN"    -, N        : Decrease Iteration   \n", 46);
	write(1, ANSI_COLOR_GREEN"    Scroll UP   : Zoom_In              \n", 46);
	write(1, ANSI_COLOR_GREEN"    Scroll Down : Zoom_Out             \n", 46);
	write(1, ANSI_COLOR_GREEN"    Left Click  : Stop Julia_Set       \n", 46);
	write(1, ANSI_COLOR_GREEN"    C           : Change Color         \n", 46);
	write(1, ANSI_COLOR_GREEN"    R           : Reset                \n", 48);
	write(1, ANSI_COLOR_GREEN"    X, ESC, Q   : QUIT                 \n", 46);
	write(1, ANSI_COLOR_GREEN"                                       \n", 46);
	write(1, ANSI_COLOR_GREEN"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 46);
}
