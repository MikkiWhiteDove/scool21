/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:18:15 by sreyne            #+#    #+#             */
/*   Updated: 2019/09/18 00:19:05 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *str, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (str[len] && len < size)
		len += 1;
	i = len;
	while (src[len - i] && len + 1 < size)
	{
		str[len] = src[len - i];
		len += 1;
	}
	if (i < size)
		str[len] = '\0';
	return (i + ft_strlen(src));
}
