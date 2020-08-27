/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:01:36 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 16:29:40 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*s;

	s = (char*)b;
	c = (unsigned char)c;
	i = 0;
	while (len > 0)
	{
		s[i] = c;
		i++;
		len--;
	}
	return (b);
}
