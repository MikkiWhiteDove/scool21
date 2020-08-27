/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:06:30 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 17:24:18 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				nb_len(unsigned long int nb)
{
	int					len;

	len = 1;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char				*nb_to_str(unsigned long int n, unsigned long int len,
							char *s, unsigned long int i)
{
	unsigned long int	len_const;

	len_const = len;
	if (n < 0)
		len_const = len_const + 1;
	while (len > 0)
	{
		if (n < 0)
		{
			s[i] = '-';
			i++;
			n = -n;
		}
		if (n / 10 == 0)
			s[i++] = n + '0';
		if (n / 10 > 0)
		{
			s[i++] = (n % 10) + '0';
			n = n / 10;
		}
		len--;
	}
	s = ft_strrev(s, len_const);
	return (s);
}

char					*ft_itoa_long(unsigned long int n)
{
	char				*s;
	unsigned long int	i;
	unsigned long int	len;
	unsigned long int	len_const;

	i = 0;
	len = nb_len(n);
	len_const = len;
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == 0)
	{
		s[0] = 48;
		return (s);
	}
	s = nb_to_str(n, len, s, i);
	return (s);
}
