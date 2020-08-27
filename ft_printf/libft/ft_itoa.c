/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:28:51 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 16:28:15 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_len(int nb)
{
	int		len;

	len = 1;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char		*nb_to_str(int n, int len, char *s, int i)
{
	int		len_const;

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

char			*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		len;
	int		len_const;

	i = 0;
	len = nb_len(n);
	len_const = len;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
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
