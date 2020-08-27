/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:24:25 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/11 19:47:26 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int		get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int		get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;
	int		width_prev;

	fd = open(file_name, O_RDONLY, 0);
	width_prev = -1;
	while (get_next_line(fd, &line))
	{
		width = ft_wdcounter(line, ' ');
		width_prev = width;
		free(line);
	}
	close(fd);
	return (width);
}

int		fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
	return (i);
}

void	read_line(int fd, t_fdf *data)
{
	int		i;
	int		n;
	char	*line;

	i = 0;
	get_next_line(fd, &line);
	n = fill_matrix(data->z[i++], line);
	while (get_next_line(fd, &line))
	{
		if (n != fill_matrix(data->z[i++], line))
		{
			ft_putstr("usage: invalid map.fdf\n");
			exit(1);
		}
		free(line);
	}
	free(line);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	int		i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	if (!((fd = open(file_name, O_RDONLY, 0)) >= 0))
		ft_putstr("usage: ./fdf map.fdf\n");
	read_line(fd, data);
	close(fd);
}
