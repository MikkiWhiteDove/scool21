/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:37:26 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 17:11:53 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(t_tab *tab)
{
	tab->p = -1;
	tab->width = 0;
	tab->hash = 0;
	tab->ap2 = NULL;
	tab->minus = 0;
	tab->plus = 0;
	tab->space = 0;
	tab->zero = 0;
	tab->l_b = 0;
	tab->l = 0;
	tab->ll = 0;
	tab->h = 0;
	tab->j = 0;
	tab->z = 0;
	tab->hh = 0;
	tab->type = 0;
	ft_bzero(tab->format_flag, 5);
}

void	ft_putnbrumax(uintmax_t n)
{
	if (n > 9)
		ft_putnbrumax(n / 10);
	ft_putchar((n % 10) + '0');
}

void	ft_putnbrmax(intmax_t n)
{
	if (n == -9223372036854775807 - 1)
		write(1, "-9223372036854775808", 20);
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n > 9)
			ft_putnbrmax(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = ft_strnew(n)))
		return (NULL);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
