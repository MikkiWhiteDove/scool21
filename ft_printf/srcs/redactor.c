/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreyne <sreyne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:10:16 by sreyne            #+#    #+#             */
/*   Updated: 2020/07/25 16:15:19 by sreyne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		b_zero_int(char *string, char *s, t_tab *tab)
{
	int k;
	int i;

	i = 0;
	if (tab->format[tab->i] == 'f')
	{
		k = tab->width - ft_strlen(s);
		if (tab->negative || tab->plus || tab->space)
			k--;
	}
	else
		k = tab->p - ft_strlen(s);
	while (k > 0)
	{
		string[i++] = '0';
		k--;
	}
	string[i] = '\0';
}

static char		*common_int(char *string, char *s, t_tab *tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (string[i] == '0')
		i++;
	while (s[j])
		string[i++] = s[j++];
	string[i] = '\0';
	if (tab->negative)
		string = ft_strjoin_free("-", string, 2);
	else if (tab->plus && !tab->negative && tab->format[tab->i] != 'u')
		string = ft_strjoin_free("+", string, 2);
	else if (tab->space && tab->format[tab->i] != 'u')
		string = ft_strjoin_free(" ", string, 2);
	return (string);
}

char			*redactor(char *s, t_tab *tab)
{
	int		width;
	char	*string;

	width = max(tab->width, tab->p, ft_strlen(s));
	if (!(string = ft_strnew(width + 1)))
		exit(-1);
	tab->negative = if_minus(s);
	if (tab->format[tab->i] == 'f' && tab->zero && !tab->minus)
		b_zero_int(string, s, tab);
	if (tab->width != max(tab->width, tab->p, ft_strlen(s)))
		string = common_int(string, s, tab);
	else if (tab->width == max(tab->width, tab->p, ft_strlen(s)))
		string = common_int(string, s, tab);
	int_output(s, string, tab);
	return (string);
}
