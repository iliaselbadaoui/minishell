/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:10:14 by ielbadao          #+#    #+#             */
/*   Updated: 2019/10/09 22:14:00 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*head;
	t_list			*node;

	node = NULL;
	if (!f || !del)
		return (NULL);
	while (lst != NULL)
	{
		if (node == NULL)
		{
			if (!(head = ft_lstnew(f(lst->content))) && !f(lst->content))
				return (NULL);
			node = head;
		}
		else
		{
			if (!(node->next = ft_lstnew(f(lst->content))))
				ft_lstclear(&head, del);
			node = node->next;
		}
		lst = lst->next;
	}
	return (head);
}
