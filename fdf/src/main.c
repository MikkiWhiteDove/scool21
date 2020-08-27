/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:00:21 by sreyne            #+#    #+#             */
/*   Updated: 2020/02/11 19:33:09 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default(t_fdf *data)
{
	data->zoom = 30;
	data->z_zoom = 1;
	data->is_iso = 100;
	data->angle = 0.523599;
	data->window = 1000;
	data->shift_x = data->window / 2;
	data->shift_y = data->window / 2;
	data->mlx_ptr = mlx_init();
	data->win_ptr =\
	mlx_new_window(data->mlx_ptr, data->window, data->window, "fdf");
}

int		main(int argc, char **argv)
{
	t_fdf	*data;
	int		fd;

	if (argc == 2)
	{
		if (!((fd = open(argv[1], O_RDONLY)) >= 0))
			ft_putstr("usage: ./fdf map.fdf\n");
		data = (t_fdf *)malloc(sizeof(t_fdf));
		read_file(*++argv, data);
		set_default(data);
		draw(data);
		mlx_hook(data->win_ptr, 2, 0, deal_key, data);
		mlx_loop(data->mlx_ptr);
		close(fd);
	}
	ft_putstr("usage: ./fdf map.fdf\n");
	return (0);
}
