/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_garbage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:43:25 by ielbadao          #+#    #+#             */
/*   Updated: 2020/04/06 12:32:31 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_collect.h"

int		collect_garbage()
{
	if(!g_collection)
		return (FAIL);
	t_collection	*tmp;

	while (g_collection)
	{
		tmp = g_collection;
		free((tmp->data));
		g_collection = g_collection->next;
		free(tmp);
	}
	return (SUCCESS);
}