/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 14:53:38 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 16:17:02 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

uintmax_t	get_o(t_tab *tab, va_list arg)
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

void		convert_o(t_tab *tab, uintmax_t num, char *str, int left)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str);
	if (tab->hash && num)
		num_width++;
	not_blank = num_width;
	if (num_width <= tab->p && tab->p > 0)
		not_blank = tab->p;
	if (not_blank <= tab->width)
		tab->len += tab->width;
	else
		tab->len += not_blank;
	if (!left)
		print_gap(tab, ' ', tab->width - not_blank, 0);
	if (tab->hash && num)
		ft_putchar('0');
	print_gap(tab, '0', tab->p - num_width, 0);
	ft_putstr(str);
	free(str);
	if (left)
		print_gap(tab, ' ', tab->width - not_blank, 0);
}

void		print_o(t_tab *tab, va_list arg, int base)
{
	char		*str;
	uintmax_t	n;
	int			left;

	left = 0;
	n = get_o(tab, arg);
	if (n == 0 && tab->p == 0 && !tab->hash)
	{
		print_gap(tab, ' ', tab->width, 1);
		return ;
	}
	if (!(str = ft_itoa_base(n, base, 'a')))
		exit(-1);
	if (tab->minus)
		left = 1;
	if (tab->zero && tab->p == -1 && !tab->minus)
		tab->p = tab->width;
	convert_o(tab, n, str, left);
}
