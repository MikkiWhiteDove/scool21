/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:23:42 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/11 19:32:08 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_macos.h"

static void	cont(int key, t_fdf *data)
{
	if (key == ARROW_RIGHT)
		data->shift_x += 10;
	if (key == MAIN_PAD_PLUS || key == NUM_PAD_PLUS)
		data->zoom += 1;
	if (key == MAIN_PAD_MINUS || key == NUM_PAD_MINUS)
		data->zoom -= 1;
	if (key == NUM_PAD_5 || key == MAIN_PAD_5)
		data->is_iso = (data->is_iso) ? 0 : 1;
	if (key == NUM_PAD_8 || key == MAIN_PAD_8)
		data->z_zoom += 1;
	if (key == NUM_PAD_2 || key == MAIN_PAD_2)
		data->z_zoom -= 1;
	if (key == NUM_PAD_4 || key == MAIN_PAD_4)
		data->angle += 0.05;
	if (key == NUM_PAD_6 || key == MAIN_PAD_6)
		data->angle -= 0.05;
}

int			deal_key(int key, t_fdf *data)
{
	if (key == ARROW_UP)
		data->shift_y -= 10;
	if (key == ARROW_DOWN)
		data->shift_y += 10;
	if (key == ARROW_LEFT)
		data->shift_x -= 10;
	cont(key, data);
	if (key == 3)
	{
		data->window *= 2;
		data->win_ptr =\
		mlx_new_window(data->mlx_ptr, data->window, data->window, "fdf");
	}
	if (key == MAIN_PAD_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data);
		exit(0);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}
