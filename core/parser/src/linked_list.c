/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:30:33 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/31 11:41:02 by ielbadao         ###   ########.fr       */
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
	if (!g_history)
	{
		g_history = (t_linked *)malloc(sizeof(t_linked));
		g_history->cmd = ft_strdup(cmd);
		g_history->already = already;
		g_history->editing = 0;
		g_history->cmd_tmp = NULL;
		g_history->next = NULL;
		g_history->prev = NULL;
		g_history_the_oldest = g_history;
		return ;
	}
	tmp_prev = g_history;
	g_history->next = (t_linked *)malloc(sizeof(t_linked));
	g_history = g_history->next;
	g_history->next = NULL;
	g_history->prev = tmp_prev;
	g_history->cmd = ft_strdup(cmd);
	g_history->already = already;
	g_history->editing = 0;
	g_history->cmd_tmp = NULL;
}

void	free_last(void)
{
	t_linked	*tmp;

	if (g_history->already == 1)
		return ;
	tmp = g_history;
	g_history = g_history->prev;
	g_history->next = NULL;
	free(tmp->cmd);
	tmp->cmd = NULL;
	tmp->cmd_tmp = NULL;
	free(tmp);
	g_last = 0;
}

t_linked	*get_previous(void)
{
	if (!g_history)
		return (NULL);
	if (g_history->prev)
		g_history = g_history->prev;
	return (g_history);
}

t_linked	*get_next(void)
{
	if (!g_history_iter && g_history->already)
		return (NULL);
	if (!g_history)
		return (NULL);
	if (g_history->next)
		g_history = g_history->next;
	return (g_history);
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
	if (!g_history_to_free)
	{
		g_history_to_free = (t_linked *)malloc(sizeof(t_linked));
		g_history_to_free->cmd = cmd;
		g_history_to_free->already = 0;
		g_history_to_free->editing = 0;
		g_history_to_free->cmd_tmp = NULL;
		g_history_to_free->next = NULL;
		g_history_to_free->prev = NULL;
		return ;
	}
	tmp_prev = g_history_to_free;
	g_history_to_free->next = (t_linked *)malloc(sizeof(t_linked));
	g_history_to_free = g_history_to_free->next;
	g_history_to_free->next = NULL;
	g_history_to_free->prev = tmp_prev;
	g_history_to_free->cmd = cmd;
	g_history_to_free->already = 0;
	g_history_to_free->editing = 0;
	g_history_to_free->cmd_tmp = NULL;
}