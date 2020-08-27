/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 13:48:19 by sreyne            #+#    #+#             */
/*   Updated: 2020/07/02 16:05:04 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key.h"
#include <stdio.h>

int		ft_close(void)
{
	exit(1);
	return (0);
}

int		key3(int key, t_fractol *data)
{
	if (key == KEY_M || key == KEY_J || key == KEY_K || key == KEY_N)
	{
		if (key == KEY_M)
			data->name = 1;
		else if (key == KEY_J)
			data->name = 2;
		else if (key == KEY_K)
			data->name = 3;
		else if (key == KEY_N)
			data->name = 4;
		read_file(data);
	}
	else if (key == KEY_Q)
		data->zoom += 0.5;
	else if (key == KEY_W)
		data->zoom -= 0.5;
	return (0);
}

int		key2(int key, t_fractol *data)
{
	if (key == KEY_1)
		data->color = 265;
	else if (key == KEY_2)
		data->color = 2050;
	else if (key == KEY_3)
		data->color = 17367040;
	else if (key == KEY_4)
		data->color = 1310706;
	else if (key == KEY_6)
		data->color = color(data);
	else if (key == KEY_5)
		data->color = 2316;
	else if (key == KEY_7)
		data->color *= 2;
	else if (key == UMPER)
		data->f = !data->f;
	return (0);
}

int		key(int key, t_fractol *data)
{
	if (key == ESC)
		exit(1);
	else if (key == MINUS)
		data->it_max /= 1.5;
	else if (key == PLUS)
		data->it_max *= 1.5;
	else if (key == LEFT)
		data->x1 += 30 / data->zoom;
	else if (key == RIGNT)
		data->x1 -= 30 / data->zoom;
	else if (key == DOWN)
		data->y1 -= 30 / data->zoom;
	else if (key == UP)
		data->y1 += 30 / data->zoom;
	else if (key == SPACE)
		data->j_mouse = !data->j_mouse;
	else if (key == KEY_F)
		read_file(data);
	key2(key, data);
	key3(key, data);
	mlx_clear_window(data->mlx, data->win);
	fractol_read(data);
	return (0);
}

int		color(t_fractol *data)
{
	return ((RGB(
		127.5 * (cos((double)data->it) + 1),
		127.5 * (sin((double)data->it) + 1),
		127.5 * (1 - cos((double)data->it)))));
}
