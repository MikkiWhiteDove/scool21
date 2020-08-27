/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:01:10 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 16:33:11 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*s1;

	len = ft_strlen(s);
	s1 = (char*)s + len - 1;
	if (c == '\0')
	{
		s1++;
		return (s1);
	}
	while (len != 0)
	{
		if (*s1 == c)
			return (s1);
		len--;
		s1--;
	}
	return (NULL);
}
