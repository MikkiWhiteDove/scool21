/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:09:44 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 16:52:33 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		get_int(t_tab *tab, va_list arg)
{
	intmax_t	num;

	if (tab->hh)
		num = (signed char)(va_arg(arg, int));
	else if (tab->h)
		num = (short)(va_arg(arg, int));
	else if (tab->ll)
		num = (long long)(va_arg(arg, long long int));
	else if (tab->l)
		num = (long)(va_arg(arg, long int));
	else if (tab->j)
		num = (intmax_t)(va_arg(arg, intmax_t));
	else if (tab->z)
		num = (size_t)(va_arg(arg, size_t));
	else
		num = (int)(va_arg(arg, int));
	num = (intmax_t)num;
	return (num);
}

static int		get_tens(intmax_t num)
{
	int tens;

	if (num < 0)
		num *= -1;
	tens = 1;
	while ((num /= 10) > 0)
		tens++;
	return (tens);
}

char			get_sign(t_tab *tab, int is_neg)
{
	if (is_neg)
		return ('-');
	if (tab->plus)
		return ('+');
	if (tab->space)
		return (' ');
	return ('\0');
}

void			convert_d(t_tab *tab, intmax_t n, int num_width, int left)
{
	int			not_blank;
	char		sign;
	int			is_neg;

	is_neg = (n < 0) ? 1 : 0;
	n *= (is_neg && n != (-9223372036854775807 - 1)) ? -1 : 1;
	sign = get_sign(tab, is_neg);
	not_blank = num_width;
	if (num_width <= tab->p && tab->p >= 0)
		not_blank = tab->p;
	if (sign)
		not_blank++;
	tab->len += (not_blank <= tab->width) ? tab->width : not_blank;
	if (!left)
		print_gap(tab, ' ', tab->width - not_blank, 0);
	if (sign)
		write(1, &sign, 1);
	print_gap(tab, '0', tab->p - num_width, 0);
	if (n != (-9223372036854775807 - 1))
		ft_putnbrmax(n);
	else if ((tab->len += 18) > 0)
		write(1, "9223372036854775808", 19);
	if (left)
		print_gap(tab, ' ', tab->width - not_blank, 0);
}

void			print_int_d_i(t_tab *tab, va_list arg)
{
	intmax_t	n;
	int			num_width;
	int			left;

	n = get_int(tab, arg);
	if (n == 0 && tab->p == 0)
	{
		if (tab->plus)
			print_wchar('+', tab);
		if (tab->space)
			print_wchar(' ', tab);
		print_gap(tab, ' ', tab->width, 1);
		return ;
	}
	num_width = get_tens(n);
	left = (tab->minus) ? 1 : 0;
	if (tab->zero && tab->p == -1 && !tab->minus)
	{
		tab->p = tab->width;
		if (n < 0 || tab->space || tab->plus || tab->minus)
			tab->p--;
	}
	convert_d(tab, n, num_width, left);
}
