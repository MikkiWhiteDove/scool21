/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 13:48:45 by sreyne            #+#    #+#             */
/*   Updated: 2020/07/02 17:20:57 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_julia(int x, int y, t_fractol *data)
{
	if (data->name == 2 && data->j_mouse == 1)
	{
		data->mouse_x = x * 4;
		data->mouse_y = y * 4 - 1000;
		data->c_r = (double)data->mouse_x / 1000 - 1;
		data->c_i = (double)data->mouse_y / 400 - 1;
		mlx_clear_window(data->mlx, data->win);
		fractol_read(data);
	}
	return (0);
}

void		*fractol(void *tab)
{
	t_fractol	*data;
	int			tmp;

	data = (t_fractol *)tab;
	data->x = 0;
	tmp = data->y;
	while (data->x < SIZE)
	{
		data->y = tmp;
		while (data->y < data->y_max)
		{
			if (data->name == 1 || data->name == 4)
				mandelbrot_comp(data);
			else if (data->name == 2)
				julia_comp(data);
			else if (data->name == 3)
				chameleon_comp(data);
			data->y++;
		}
		data->x++;
	}
	data->x = 0;
	data->y = 0;
	return (tab);
}

void		fractol_read(t_fractol *data)
{
	t_fractol	tab[NUMBER];
	pthread_t	t[NUMBER];
	int			i;

	i = 0;
	while (i < NUMBER)
	{
		ft_memcpy((void *)&tab[i], (void *)data, sizeof(t_fractol));
		tab[i].y = WIDTH * i;
		tab[i].y_max = WIDTH * (i + 1);
		pthread_create(&t[i], NULL, fractol, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
