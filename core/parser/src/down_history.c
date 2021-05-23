/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:06:25 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 11:46:04 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static void	down_help(t_linked **linked, t_string *line)
{
	t_linked	*next;

	next = *linked;
	if (next)
	{
		if (!next->editing && next->already)
		{
			next->cmd_tmp = ft_strdup(next->cmd);
			add_node_to_free(next->cmd_tmp);
			next->editing = 1;
		}
		if (next->already)
			*line = next->cmd_tmp;
		else
			*line = ft_strdup(next->cmd);
		tputs(tgetstr("ce", NULL), 1, move_cursor);
		write_to_stdout(*line);
		if (g_container->history_iter > 0)
			g_container->history_iter--;
		if (!g_container->history_iter)
			free_last();
	}
}

void	down_history(char **line, int line_length)
{
	char		*pos;
	t_linked	*next;

	if (g_container->history && g_container->history->next)
	{
		while (line_length)
		{
			pos = tgetstr("le", NULL);
			tputs(pos, 1, move_cursor);
			line_length--;
		}
		if (g_container->history->editing)
			g_container->history->cmd_tmp = *line;
		next = get_next();
		down_help(&next, line);
	}
}
