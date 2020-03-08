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

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list			*node;

	node = *alst;
	if (!node)
		*alst = new;
	else
	{
		while (node->next)
			node = node->next;
		node->next = new;
	}
}
