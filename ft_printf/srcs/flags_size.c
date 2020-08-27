/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:16:04 by sreyne            #+#    #+#             */
/*   Updated: 2020/07/25 17:16:05 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_bonus(char *format, t_tab *tab)
{
	if (format[tab->i] == 'L')
	{
		tab->l_b = 1;
		tab->i++;
	}
	else if (format[tab->i] == 'z')
	{
		tab->z = 1;
		tab->i++;
	}
	else if (format[tab->i] == 'j')
	{
		tab->j = 1;
		tab->i++;
	}
}

void	size_parse(char *format, t_tab *tab)
{
	if (format[tab->i] == 'h')
	{
		tab->i++;
		if (format[tab->i] == 'h')
		{
			tab->hh = 1;
			tab->i++;
		}
		else
			tab->h = 1;
	}
	else if (format[tab->i] == 'l')
	{
		tab->i++;
		if (format[tab->i] == 'l')
		{
			tab->ll = 1;
			tab->i++;
		}
		else
			tab->l = 1;
	}
	flag_bonus(format, tab);
}

void	flag_pars(const char *format, t_tab *tab)
{
	size_t i;

	i = tab->i;
	while (format[i] == '-' || format[i] == '+' || format[i] == ' ' ||
			format[i] == '#' || format[i] == '0')
	{
		if (format[i] == '#')
			tab->hash = '#';
		else if (format[i] == '-')
			tab->minus = format[i];
		else if ((format[i] == '+'))
			tab->plus = format[i];
		else if ((format[i] == ' '))
			tab->space = format[i];
		else if ((format[i] == '0'))
			tab->zero = format[i];
		i = ++tab->i;
	}
}
