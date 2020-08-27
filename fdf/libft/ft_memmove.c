/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:37:26 by sreyne            #+#    #+#             */
/*   Updated: 2019/09/18 22:11:54 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*srcc;
	unsigned char	*dstc;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	dstc = (unsigned char*)dst;
	srcc = (unsigned char*)src;
	i = 0;
	if (srcc < dstc)
		while (++i <= len)
			dstc[len - i] = srcc[len - i];
	else
		while (len-- > 0)
			*(dstc++) = *(srcc++);
	return (dst);
}
