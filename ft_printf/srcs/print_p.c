/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:57:56 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 16:48:15 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				convert_p(t_tab *tab, char *str, int left)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str) + 2;
	not_blank = num_width;
	if (not_blank <= tab->width)
		tab->len += tab->width;
	else
		tab->len += not_blank;
	if (!left)
		print_gap(tab, ' ', tab->width - not_blank, 0);
	write(1, "0x", 2);
	print_gap(tab, '0', (tab->p - num_width) + 2, 1);
	ft_putstr(str);
	if (left)
		print_gap(tab, ' ', tab->width - not_blank, 0);
	free(str);
}

void				print_p(t_tab *tab, va_list arg)
{
	char		*str;
	uintmax_t	n;
	int			left;

	n = (unsigned long)(va_arg(arg, unsigned long int));
	n = (uintmax_t)n;
	left = 0;
	if (!(str = ft_itoa_base(n, 16, 'a')))
		exit(-1);
	if (tab->minus)
		left = 1;
	if (tab->p == 0 && n == 0)
		*str = '\0';
	if (tab->zero && tab->p == -1 && !tab->minus)
	{
		tab->p = tab->width - 2;
		tab->width = 0;
	}
	convert_p(tab, str, left);
}
