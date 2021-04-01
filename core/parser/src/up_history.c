/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:08:59 by ielbadao          #+#    #+#             */
/*   Updated: 2021/04/01 09:38:05 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void		up_history(char **line, int line_length)
{
	char		*pos;
	t_linked	*prev;

	if (g_history && (!g_history->is_visited || g_history->prev))
	{
		while (line_length)
		{
			pos = tgetstr("le", NULL);
			tputs(pos, 1, move_cursor);
			line_length--;
		}
		if (!g_history_iter)
		{
			add_node(*line, 0);
			free(*line);
		}
		if (g_history->editing)
			g_history->cmd_tmp = *line;
		prev = get_previous();
		if (!prev->editing && prev->already)
		{
			prev->cmd_tmp = ft_strdup(prev->cmd);
			add_node_to_free(prev->cmd_tmp);
			prev->editing = 1;
		}
		if (prev->already)
			*line = prev->cmd_tmp;
		tputs(tgetstr("ce", NULL), 1, move_cursor);
		write_to_stdout(*line);
		g_history_iter++;
	}
}
