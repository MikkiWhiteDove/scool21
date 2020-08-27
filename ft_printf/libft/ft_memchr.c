/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 23:05:04 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 16:29:13 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	size_t			i;
	unsigned char	c1;

	c1 = (unsigned char)c;
	i = 0;
	s1 = (unsigned char*)s;
	while (i < n)
	{
		if (*s1 == c1)
			return (s1);
		i++;
		s1++;
	}
	return (NULL);
}
