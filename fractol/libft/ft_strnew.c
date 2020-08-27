/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:02:40 by sreyne            #+#    #+#             */
/*   Updated: 2019/09/19 16:14:56 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*res;

	if (!(res = (char *)ft_memalloc(size + 1)))
		return (0);
	i = 0;
	while (i < size)
		res[i++] = '\0';
	return (res);
}
