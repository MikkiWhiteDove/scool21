/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:09:29 by sreyne            #+#    #+#             */
/*   Updated: 2020/07/25 17:35:17 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		int_output(char *s, char *string, t_tab *tab)
{
	ft_putstr(string);
	tab->len += ft_strlen(string);
	free(s);
	free(string);
}

int			max(int a, int b, int c)
{
	int k;

	k = a > b ? a : b;
	if (k > c)
		return (k);
	else
		return (c);
	return (0);
}

int			if_minus(char *s)
{
	int minus;
	int i;

	i = 0;
	if (s[i] == '-')
	{
		minus = 1;
		i++;
		while (s[i])
		{
			s[i - 1] = s[i];
			i++;
		}
		s[i - 1] = '\0';
	}
	else
		minus = 0;
	return (minus);
}
