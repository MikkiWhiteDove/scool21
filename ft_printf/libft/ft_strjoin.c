/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:12:18 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 16:32:12 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*s3;

	if (s1 && s2)
	{
		s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (s3)
		{
			i = 0;
			while (*s1)
			{
				s3[i++] = *s1;
				s1++;
			}
			while (*s2)
			{
				s3[i++] = *s2;
				s2++;
			}
			s3[i] = '\0';
			return (s3);
		}
	}
	return (NULL);
}
