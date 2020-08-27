/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:00:57 by sreyne            #+#    #+#             */
/*   Updated: 2020/02/11 19:10:57 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			zoom;
	int			color;
	int			**z;
	int			is_iso;
	float		angle;
	int			window;
	int			shift_x;
	int			shift_y;

	void		*mlx_ptr;
	void		*win_ptr;
	int			z_zoom;
}				t_fdf;

typedef struct	s_xy
{
	float		x;
	float		y;
}				t_xy;

void			read_file(char *file_name, t_fdf *data);
void			draw(t_fdf *data);
int				deal_key(int key, t_fdf *data);
int				isometric(float *x, float *y, int z, float angle);
int				deal_key(int key, t_fdf *data);
void			print_menu(t_fdf data);

#endif
