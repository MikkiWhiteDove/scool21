/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:25:30 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 16:32:33 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s1;

	s1 = NULL;
	i = 0;
	if (s && f)
	{
		if (!(s1 = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1))))
			return (NULL);
		while (s[i] != '\0')
		{
			s1[i] = f(i, s[i]);
			i++;
		}
		s1[i] = '\0';
	}
	return (s1);
}
