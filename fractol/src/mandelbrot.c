/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 13:49:19 by sreyne            #+#    #+#             */
/*   Updated: 2020/07/02 16:01:25 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_def(t_fractol *data)
{
	data->zoom = 200;
	data->color = 265;
	data->x1 = -2.05;
	data->y1 = -1.3;
	data->it_max = 50;
	data->f = 1;
}

void	mandelbrot_comp(t_fractol *data)
{
	data->c_r = data->x / data->zoom + data->x1;
	data->c_i = data->y / data->zoom + data->y1;
	data->z_r = 0;
	data->z_i = 0;
	data->tm = (data->name == 1) ? 2 : -2;
	data->it = 0;
	while (data->z_r * data->z_r + data->z_i * data->z_i < 4
			&& data->it < data->it_max)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_r * data->z_r -
			data->z_i * data->z_i + data->c_r;
		data->z_i = data->tm * data->z_i * data->tmp + data->c_i;
		data->it++;
	}
	if (data->it == data->it_max && data->f == 1)
		put_pxl_to_img(data, data->x, data->y, 000000);
	else if (data->it == data->it_max && !data->f)
		put_pxl_to_img(data, data->x, data->y, 0xffffff);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * data->it));
}
