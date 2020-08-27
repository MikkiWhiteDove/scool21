/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 13:48:34 by sreyne            #+#    #+#             */
/*   Updated: 2020/07/02 16:41:35 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdio.h"

void	fractol_zed(t_fractol *data)
{
	if (data->it_max < 0)
		data->it_max = 0;
	fractol_read(data);
}

void	set_default(t_fractol *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SIZE, SIZE, "Fractol");
	data->img = mlx_new_image(data->mlx, SIZE, SIZE);
	data->img_ptr = mlx_get_data_addr(data->img,
				&data->bpp, &data->sl, &data->endian);
	fractol_zed(data);
	mlx_hook(data->win, 6, 1L < 6, mouse_julia, data);
	mlx_hook(data->win, 17, 0L, ft_close, data);
	mlx_hook(data->win, 2, 0, key, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_loop(data->mlx);
}

int		read_file(t_fractol *data)
{
	if (ft_strcmp(&data->copy_name, "mandelbrot") == 0 || data->name == 1)
	{
		mandelbrot_def(data);
		data->name = 1;
	}
	else if (ft_strcmp(&data->copy_name, "julia") == 0 || data->name == 2)
	{
		julia_def(data);
		data->name = 2;
	}
	else if (ft_strcmp(&data->copy_name, "chameleon") == 0 || data->name == 3)
	{
		chameleon_def(data);
		data->name = 3;
	}
	else if (ft_strcmp(&data->copy_name, "tricorn") == 0 || data->name == 4)
	{
		mandelbrot_def(data);
		data->name = 4;
	}
	else
		return (0);
	ft_strcpy(&data->copy_name, "dot");
	return (1);
}

int		main(int ac, char **av)
{
	t_fractol *data;

	if (av[1] == NULL)
	{
		ft_putndl(("Usage/ fractol: mandelbrot, julia, chameleon, tricorn"));
		return (0);
	}
	if (!(data = (t_fractol *)malloc(sizeof(t_fractol))))
		return (-1);
	ft_strcpy(&data->copy_name, av[1]);
	if ((ac != 2) || ((read_file(data)) == 0))
	{
		ft_putndl(("Usage/ fractol: mandelbrot, julia, chameleon, tricorn"));
		return (0);
	}
	set_default(data);
	return (0);
}
