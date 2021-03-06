/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 09:50:29 by jsankari          #+#    #+#             */
/*   Updated: 2020/09/12 17:08:19 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *result;

	if (!(lst))
		return (NULL);
	if (!(result = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	result = f(lst);
	newlist = result;
	lst = lst->next;
	while (lst)
	{
		newlist->next = f(lst);
		lst = lst->next;
		newlist = newlist->next;
	}
	return (result);
}
