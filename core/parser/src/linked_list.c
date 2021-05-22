/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:30:33 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 00:39:50 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	add_node(char *cmd, int already)
{
	t_linked	*tmp_prev;

	if (!cmd)
		return ;
	if (already == 1 && *cmd == 0)
		return ;
	if (!g_container->history)
	{
		g_container->history = (t_linked *)malloc(sizeof(t_linked));
		g_container->history->cmd = ft_strdup(cmd);
		g_container->history->already = already;
		g_container->history->editing = 0;
		g_container->history->is_visited = 0;
		g_container->history->cmd_tmp = NULL;
		g_container->history->next = NULL;
		g_container->history->prev = NULL;
		g_container->history_the_oldest = g_container->history;
		return ;
	}
	tmp_prev = g_container->history;
	g_container->history->next = (t_linked *)malloc(sizeof(t_linked));
	g_container->history = g_container->history->next;
	g_container->history->next = NULL;
	g_container->history->is_visited = 0;
	g_container->history->prev = tmp_prev;
	g_container->history->cmd = ft_strdup(cmd);
	g_container->history->already = already;
	g_container->history->editing = 0;
	g_container->history->cmd_tmp = NULL;
}

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

void	add_node_to_free(char *cmd)
{
	t_linked	*tmp_prev;

	if (!cmd)
		return ;
	if (*cmd == 0)
		return ;
	if (!g_container->history_to_free)
	{
		g_container->history_to_free = (t_linked *)malloc(sizeof(t_linked));
		g_container->history_to_free->cmd = cmd;
		g_container->history_to_free->already = 0;
		g_container->history_to_free->editing = 0;
		g_container->history_to_free->cmd_tmp = NULL;
		g_container->history_to_free->next = NULL;
		g_container->history_to_free->prev = NULL;
		return ;
	}
	tmp_prev = g_container->history_to_free;
	g_container->history_to_free->next = (t_linked *)malloc(sizeof(t_linked));
	g_container->history_to_free = g_container->history_to_free->next;
	g_container->history_to_free->next = NULL;
	g_container->history_to_free->prev = tmp_prev;
	g_container->history_to_free->cmd = cmd;
	g_container->history_to_free->already = 0;
	g_container->history_to_free->editing = 0;
	g_container->history_to_free->cmd_tmp = NULL;
}