/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:56:10 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 18:03:28 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		calc(char *fr, long double nbr)
{
	int			apr;
	int			i;

	i = ft_strlen(fr);
	nbr *= 10;
	apr = (int)nbr;
	apr %= 10;
	if (apr >= 5)
		while (i)
		{
			if (fr[--i] != '9')
			{
				fr[i] += 1;
				return (0);
			}
			else
				fr[i] = '0';
		}
	else
		return (0);
	return (1);
}

static char		*ft_stradd(char *str, char c)
{
	int			len;
	char		*new;

	len = 0;
	if (str)
	{
		len = ft_strlen(str);
		if (!(new = (char*)ft_strnew(len + 1)))
			return (NULL);
		ft_strcat(new, str);
		ft_strdel(&str);
	}
	else
	{
		new = (char*)ft_strnew(1);
		if (new == NULL)
			return (NULL);
	}
	new[len] = c;
	new[len + 1] = '\0';
	return (new);
}

char			*ft_ftoa_long(long double nbr, unsigned int p)
{
	int			i;
	size_t		whole;
	char		fr[NUMBER];
	int			sign;
	char		ch;

	ch = (p) ? '.' : '\0';
	sign = (nbr < 0) ? -1 : 1;
	nbr = nbr * sign;
	whole = (size_t)nbr;
	nbr -= whole;
	i = 0;
	if (p <= NUMBER)
		while (p--)
		{
			nbr *= 10;
			fr[i++] = (size_t)nbr % 10 + '0';
			nbr -= (size_t)nbr;
		}
	fr[i] = '\0';
	whole += calc(fr, nbr);
	return (sign < 0) ? ft_strjoin_free("-",
	ft_strjoin_free(ft_stradd(ft_itoa_unsigned(whole), ch), fr, 1), 2) :
	ft_strjoin_free(ft_stradd(ft_itoa_unsigned(whole), ch), fr, 1);
}

char			*ft_ftoa(double nbr, unsigned int p)
{
	return (ft_ftoa_long(nbr, p));
}
