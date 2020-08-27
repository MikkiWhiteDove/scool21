/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:36:12 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 16:29:07 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;
	unsigned char	c1;

	i = 0;
	dst1 = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	c1 = (unsigned char)c;
	while (i < n)
	{
		*dst1 = src1[i];
		dst1++;
		if (src1[i] == c1)
			return (dst1);
		i++;
	}
	return (NULL);
}
