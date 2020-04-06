/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:00:30 by ielbadao          #+#    #+#             */
/*   Updated: 2020/03/07 16:40:41 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_collect.h"

void		*safe_malloc(ssize_t size)
{
	t_collection	*tmp;
	void			*data;

	if (!(data = malloc(size)))
		free(data);
	if(!g_collection || !data)
	{
		g_collection = (t_collection *)malloc(sizeof(t_collection));
		g_collection->data = data;
		g_collection->next = NULL;
		return (data);
	}
	else if (data)
	{
		tmp = g_collection;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_collection *)malloc(sizeof(t_collection));
		tmp = tmp->next;
		tmp->data = data;
		tmp->next = NULL;
		return (data);
	}
	return (NULL);
}