/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chameleon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 13:49:07 by sreyne            #+#    #+#             */
/*   Updated: 2020/07/02 16:07:40 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	chameleon_def(t_fractol *data)
{
	data->color = 265;
	data->it = 50;
	data->x1 = -1.5;
	data->y1 = -1.5;
	data->c_r = 0.29;
	data->c_i = 0.02;
	data->it_max = 5;
	data->zoom = 200;
}

void	chameleon_comp(t_fractol *data)
{
	data->c_r = data->c_r;
	data->c_i = data->c_i;
	data->z_r = data->x / data->zoom + data->x1;
	data->z_i = data->y / data->zoom + data->y1;
	data->it = 0;
	while (data->z_r * data->z_r + data->z_i * data->z_i < 4 && data->it_max)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
		data->z_i = -2 * data->z_i * data->tmp + data->c_i;
		data->it++;
	}
	if (data->it == data->it_max)
		put_pxl_to_img(data, data->c_r, data->c_i, data->it);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * data->it));
}
