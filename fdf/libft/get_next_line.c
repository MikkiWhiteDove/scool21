/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:59:06 by sreyne            #+#    #+#             */
/*   Updated: 2020/02/10 08:43:23 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fd	*newlist(const int fd)
{
	t_fd	*new;

	if (!(new = (t_fd *)malloc(sizeof(t_fd))))
		return (NULL);
	new->fd = fd;
	new->remain = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

char	*check_remainder(char **new_str, char *remain)
{
	char *p_n;

	if ((*new_str = ft_strchr(remain, '\n')) != NULL)
	{
		p_n = ft_strsub(remain, 0, *new_str - remain);
		ft_strcpy(remain, ++(*new_str));
	}
	else
	{
		p_n = ft_strnew(ft_strlen(remain) + 1);
		ft_strcat(p_n, remain);
		ft_strclr(remain);
	}
	return (p_n);
}

int		get_line(const int fd, char **line, char *remain)
{
	char			*new_str;
	char			buf[BUFF_SIZE + 1];
	int				bwr;
	char			*tmp;

	new_str = NULL;
	bwr = 1;
	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	*line = check_remainder(&new_str, remain);
	while (new_str == 0 && ((bwr = read(fd, buf, BUFF_SIZE)) != 0))
	{
		buf[bwr] = '\0';
		if ((new_str = ft_strchr(buf, '\n')) != NULL)
		{
			ft_strcpy(remain, ++new_str);
			ft_strclr(--new_str);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || bwr < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return (ft_strlen(remain) || ft_strlen(*line) || bwr) ? 1 : 0;
}

int		get_next_line(const int fd, char **line)
{
	static	t_fd	*list;
	t_fd			*tmp;
	int				ret;

	if (fd < 0 || line == 0)
		return (-1);
	if (!list)
		list = newlist(fd);
	tmp = list;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
		{
			if (((tmp->next = newlist(fd)) == NULL))
				return (-1);
		}
		tmp = tmp->next;
	}
	ret = get_line(fd, line, tmp->remain);
	return (ret);
}
