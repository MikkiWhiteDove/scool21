/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:45:06 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 17:19:37 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_tab(t_tab *tab)
{
	tab->i = 0;
	tab->len = 0;
	tab->tmp = NULL;
	tab->tmp_len = 0;
	tab->tmp = (char*)malloc(sizeof(char) * 100);
}

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	t_tab		*tab;
	int			len;

	tab = NULL;
	len = 0;
	if (!(tab = (t_tab*)malloc(sizeof(t_tab))))
		return (0);
	tab->format = (char*)format;
	if (format)
	{
		va_start(arg, format);
		init_tab(tab);
		form_parser(tab, arg);
		va_end(arg);
		free(tab->tmp);
	}
	len = tab->len;
	free(tab);
	return (len);
}
