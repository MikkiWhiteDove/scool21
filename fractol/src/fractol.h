/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:18:12 by sreyne            #+#    #+#             */
/*   Updated: 2020/07/07 17:38:35 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include <fcntl.h>

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

# define SIZE_H 500
# define SIZE 600
# define NUMBER 200
# define WIDTH 5

# define RGB(r, g, b) (256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

typedef struct	s_fractol
{

	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			endian;
	int			sl;
	int			bpp;
	int			name;
	double		color;
	int			j_mouse;
	int			x;
	int			y;
	int			y_max;
	int			it;
	int			it_max;
	double		zoom;
	double		x1;
	double		y1;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
	int			f;
	int			i;
	int			mouse_x;
	int			mouse_y;
	int			tm;
	char		copy_name;
}				t_fractol;

int				key(int key, t_fractol *data);

void			mandelbrot_def(t_fractol *data);
void			mandelbrot_read(t_fractol *data);
void			*mandelbrot(void *tab);
void			mandelbrot_comp(t_fractol *data);

void			julia_def(t_fractol *data);
void			julia_read(t_fractol *data);
void			julia_comp(t_fractol *data);
void			*julia(void *tab);

void			put_pxl_to_img(t_fractol *data, int x, int y, int color);
int				ft_close(void);

void			fract_init(t_fractol *data);
void			set_default(t_fractol *data);
int				read_file(t_fractol *data);

void			*fractol(void *tab);
void			fractol_read(t_fractol *data);

void			chameleon_def(t_fractol *data);
void			chameleon_comp(t_fractol *data);
void			chameleon(t_fractol *data);

void			fractol_zed(t_fractol *data);

int				color(t_fractol *data);
void			fractol_def(t_fractol *data);
int				mouse_julia(int x, int y, t_fractol *data);
int				mouse_hook(int mousecode, int x, int y, t_fractol *data);
#endif
