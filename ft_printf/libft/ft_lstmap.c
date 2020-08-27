/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:50:35 by mgalt             #+#    #+#             */
/*   Updated: 2020/07/25 16:28:49 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*new_list;

	if (!(list = (t_list*)malloc(sizeof(*list))) || !f)
		return (NULL);
	list = f(lst);
	new_list = list;
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
			if (!(list->next = f(lst)))
			{
				free(list->next);
				return (NULL);
			}
			list = list->next;
		}
	}
	return (new_list);
}
