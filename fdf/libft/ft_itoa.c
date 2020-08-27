/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:59:50 by sreyne            #+#    #+#             */
/*   Updated: 2019/09/19 21:33:15 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_lenghth(int nb)
{
	int		i;

	i = 1;
	while ((nb = nb / 10))
	{
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	int				sign;
	int				len;
	char			*str;

	sign = 1;
	len = ft_lenghth(n);
	if (n < 0)
	{
		sign = -1;
		len++;
	}
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	if (sign == -1)
		str[0] = '-';
	while (len > -sign)
	{
		str[--len] = (n % 10) * sign + '0';
		n = n / 10;
	}
	return (str);
}
