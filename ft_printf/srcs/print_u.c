/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 23:10:01 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 16:54:06 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	get_u(t_tab *tab, va_list arg)
{
	uintmax_t	num;

	if (tab->hh)
		num = (unsigned char)(va_arg(arg, unsigned int));
	else if (tab->h)
		num = (unsigned short)(va_arg(arg, unsigned int));
	else if (tab->ll)
		num = (unsigned long long)(va_arg(arg, unsigned long long int));
	else if (tab->l)
		num = (unsigned long)(va_arg(arg, unsigned long int));
	else if (tab->j)
		num = (uintmax_t)(va_arg(arg, uintmax_t));
	else if (tab->z)
		num = (size_t)(va_arg(arg, size_t));
	else
		num = (unsigned int)(va_arg(arg, unsigned int));
	num = (uintmax_t)num;
	return (num);
}

static int	get_tens(uintmax_t num)
{
	int tens;

	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

void		convert_u(t_tab *tab, uintmax_t num, int num_width, int left)
{
	int			not_blank;

	not_blank = num_width;
	if (num_width <= tab->p)
		not_blank = tab->p;
	if (not_blank <= tab->width)
		tab->len += tab->width;
	else
		tab->len += not_blank;
	if (!left)
		print_gap(tab, ' ', tab->width - not_blank, 0);
	print_gap(tab, '0', tab->p - num_width, 0);
	ft_putnbrumax(num);
	if (left)
		print_gap(tab, ' ', tab->width - not_blank, 0);
}

void		print_int_u(t_tab *tab, va_list arg)
{
	uintmax_t	num;
	int			num_width;
	int			left;

	left = 0;
	num = get_u(tab, arg);
	if (num == 0 && tab->p == 0)
	{
		print_gap(tab, ' ', tab->width, 1);
		return ;
	}
	num_width = get_tens(num);
	if (tab->minus)
		left = 1;
	if (tab->zero && tab->p == -1 && !tab->minus)
		tab->p = tab->width;
	convert_u(tab, num, num_width, left);
}
