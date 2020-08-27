/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:00:43 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 16:33:21 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_word_length(char const *s, char c, unsigned int i)
{
	unsigned int len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		++len;
		++i;
	}
	return (len);
}

static int	ft_array_length(char const *s, char c)
{
	unsigned int len;

	len = 0;
	while (*s)
	{
		if (*s == c)
			++s;
		else
		{
			++len;
			while (*s && *s != c)
				++s;
		}
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**ar;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!(ar = (char **)malloc(sizeof(char *) * (ft_array_length(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!(ar[j++] = ft_strsub(s, i, ft_word_length(s, c, i))))
				return (NULL);
			i += ft_word_length(s, c, i);
		}
		else
			i++;
	}
	ar[j] = NULL;
	return (ar);
}
