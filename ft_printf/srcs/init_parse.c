/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:26:55 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 17:12:08 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_precision(char *tmp, t_tab *tab)
{
	while (tmp[tab->i] == '.')
	{
		tab->i++;
		tab->p = 0;
	}
	while (tmp[tab->i] >= '0' && tmp[tab->i] <= '9')
	{
		tab->p *= 10;
		tab->p += (tmp[tab->i] - 48);
		tab->i++;
	}
}

void	check_width(char *tmp, t_tab *tab)
{
	while (tmp[tab->i] >= '0' && tmp[tab->i] <= '9')
	{
		tab->width *= 10;
		tab->width += (tmp[tab->i] - 48);
		tab->i++;
	}
}

int		valid_type(char type)
{
	if (type == 'd' || type == 'i' || type == 'o' ||
	type == 'u' || type == 'x' || type == 'X' ||
	type == 'c' || type == 's' || type == 'p' ||
	type == 'f' || type == 'b' || type == '%')
		return (1);
	if (type == 'D' || type == 'I' || type == 'O' ||
	type == 'U' || type == 'C' || type == 'S' || type == 'P' ||
	type == 'F' || type == 'B')
		return (1);
	return (0);
}

void	parse(t_tab *tab, va_list arg)
{
	init(tab);
	flag_pars(tab->format, tab);
	check_width(tab->format, tab);
	check_precision(tab->format, tab);
	size_parse(tab->format, tab);
	tab->type = tab->format[tab->i];
	if ((valid_type(tab->type)))
		check_type(tab, arg);
}

void	form_parser(t_tab *tab, va_list arg)
{
	if ((ft_strcmp(tab->format, "%") == 0))
		return ;
	while (tab->format[tab->i] != '\0')
	{
		if (tab->format[tab->i] == '%')
		{
			if (tab->format[tab->i + 1] == '%')
			{
				write(1, "%", 1);
				tab->len += 1;
				tab->i++;
			}
			else
			{
				tab->i++;
				parse(tab, arg);
			}
		}
		else
		{
			ft_putchar(tab->format[tab->i]);
			tab->len++;
		}
		tab->i++;
	}
}
