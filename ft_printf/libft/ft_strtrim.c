/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:24:35 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 16:33:38 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s1;
	int		i;
	int		n;
	int		len;

	if (!s)
		return (NULL);
	n = ft_strlen(s) - 1;
	i = 0;
	len = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[n] == ' ' || s[n] == '\n' || s[n] == '\t')
		n--;
	len = n - i + 1;
	if (len <= 0)
		return (ft_strnew(0));
	else
		s1 = ft_strnew(len);
	if (s1)
		return (ft_strsub(s, i, len));
	return (NULL);
}
