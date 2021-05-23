/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:54:48 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 11:55:15 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	free_last(void)
{
	t_linked	*tmp;

	if (g_container->history->already == 1)
		return ;
	tmp = g_container->history;
	g_container->history = g_container->history->prev;
	g_container->history->next = NULL;
	free(tmp->cmd);
	tmp->cmd = NULL;
	tmp->cmd_tmp = NULL;
	free(tmp);
	g_container->last = 0;
}

t_linked	*get_previous(void)
{
	if (!g_container->history)
		return (NULL);
	if (g_container->history->prev)
	{
		g_container->history->is_visited = 0;
		g_container->history = g_container->history->prev;
		g_container->history->is_visited = 1;
	}
	return (g_container->history);
}

t_linked	*get_next(void)
{
	if (!g_container->history_iter && g_container->history->already)
		return (NULL);
	if (!g_container->history)
		return (NULL);
	if (g_container->history->next)
	{
		g_container->history->is_visited = 0;
		g_container->history = g_container->history->next;
		g_container->history->is_visited = 1;
	}
	return (g_container->history);
}

void	free_linked_list(t_linked *history)
{
	t_linked	*tmp;

	while (history->prev)
	{
		tmp = history;
		history = history->prev;
		free(tmp->cmd);
		free(tmp);
	}
}
