/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:06:46 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 16:12:22 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

void		print_zero_x(uintmax_t n, char hash, char x)
{
	if (n)
	{
		if (hash == '#' && x == 'x')
			ft_putstr("0x");
		if (hash == '#' && x == 'X')
			ft_putstr("0X");
	}
}

uintmax_t	get_x(t_tab *tab, va_list arg)
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

void		convert_x(t_tab *tab, uintmax_t num, char *str, int left)
{
	int			new_width;
	int			new_len;

	if ((new_len = ft_strlen(str)) && tab->hash && num &&
			tab->zero && tab->width)
		new_len += 2;
	else if ((new_len = ft_strlen(str)) && tab->hash && num)
	{
		tab->width -= 2;
		tab->len += 2;
	}
	new_width = (new_len <= tab->p && tab->p > 0) ? tab->p : new_len;
	tab->len += (new_width <= tab->width) ? tab->width : new_width;
	if (!left)
		print_gap(tab, ' ', tab->width - new_width, 0);
	print_zero_x(num, tab->hash, tab->type);
	print_gap(tab, '0', tab->p - new_len, 0);
	ft_putstr(str);
	if (left)
		print_gap(tab, ' ', tab->width - new_width, 0);
}

void		print_x(t_tab *tab, va_list arg)
{
	char		*str;
	char		c;
	uintmax_t	n;
	int			left;

	n = get_x(tab, arg);
	left = 0;
	if (n == 0 && tab->p == 0)
	{
		print_gap(tab, ' ', tab->width, 1);
		return ;
	}
	c = 'a';
	if (tab->type == 'X')
		c = 'A';
	if (!(str = ft_itoa_base(n, 16, c)))
		exit(-1);
	if (tab->minus)
		left = 1;
	if (tab->zero && tab->p == -1 && !tab->minus)
		tab->p = tab->width;
	convert_x(tab, n, str, left);
	free(str);
}
