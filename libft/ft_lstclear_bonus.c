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

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list			*node;
	t_list			*tmp;

	node = *lst;
	while (node)
	{
		tmp = node;
		node = node->next;
		if (tmp->content && del)
			del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
