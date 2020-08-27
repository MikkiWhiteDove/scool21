/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:03:44 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 15:59:25 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_tab *tab, va_list arg)
{
	wint_t		c;

	if (tab->l)
		c = (unsigned long)va_arg(arg, unsigned long);
	else
		c = (char)va_arg(arg, int);
	c = (wint_t)c;
	if (tab->zero && !tab->minus)
		print_gap(tab, '0', tab->width - 1, 1);
	else if (!tab->minus)
		print_gap(tab, ' ', tab->width - 1, 1);
	print_wchar(c, tab);
	if (tab->minus)
		print_gap(tab, ' ', tab->width - 1, 1);
}

void	print_str(va_list arg, t_tab *tab)
{
	char		*s;
	int			i;
	int			len;

	i = 0;
	s = va_arg(arg, char *);
	if (tab->p > -1 && s)
		s = ft_strndup(s, tab->p);
	else if (tab->p == -1 && s)
		s = ft_strdup(s);
	else if (tab->p > -1 && !s)
		s = ft_strndup("(null)", tab->p);
	else if (tab->p == -1 && !s)
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	tab->len += len;
	if (tab->zero && !tab->minus)
		print_gap(tab, '0', tab->width - len, 1);
	else if (!tab->minus)
		print_gap(tab, ' ', tab->width - len, 1);
	ft_putstr(s);
	if (tab->minus)
		print_gap(tab, ' ', tab->width - len, 1);
	free(s);
}

void	print_gap(t_tab *tab, char c, int len, int update_len)
{
	char	*str;

	if (len > 0)
	{
		if (update_len)
			tab->len += len;
		if (!(str = ft_strnew(len)))
			exit(-1);
		ft_memset(str, c, len);
		write(1, str, len);
		free(str);
	}
}

void	print_percent(t_tab *tab)
{
	int		len;
	char	c;

	c = ' ';
	if (tab->minus)
		ft_putchar('%');
	len = tab->width - 1;
	if (tab->zero && !tab->minus)
		c = '0';
	while (len > 0)
	{
		ft_putchar(c);
		len--;
	}
	if (!tab->minus)
		ft_putchar('%');
	if (tab->width)
		tab->len += tab->width;
	else
		tab->len += 1;
}
