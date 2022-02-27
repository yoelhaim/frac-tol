/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:13:03 by yoelhaim          #+#    #+#             */
/*   Updated: 2022/02/27 22:57:36 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACT_H
# define FRACT_H
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125

 typedef struct s_fract
 {
	void	*mlx;
	void	*mlx_win;
	double	re_start;
	double	re_end;
	double	im_start;
	double	im_end;
 }t_fract;

#endif
