/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 11:30:33 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 11:59:24 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static void	add_node_help(char *cmd, int already, t_linked *tmp_prev)
{
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
	add_node_help(cmd, already, tmp_prev);
}

static void	add_node_free_help(char *cmd, t_linked *tmp_prev)
{
	g_container->history_to_free->next = (t_linked *)malloc(sizeof(t_linked));
	g_container->history_to_free = g_container->history_to_free->next;
	g_container->history_to_free->next = NULL;
	g_container->history_to_free->prev = tmp_prev;
	g_container->history_to_free->cmd = cmd;
	g_container->history_to_free->already = 0;
	g_container->history_to_free->editing = 0;
	g_container->history_to_free->cmd_tmp = NULL;
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
	add_node_free_help(cmd, tmp_prev);
}
