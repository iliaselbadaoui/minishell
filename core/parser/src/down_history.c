/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:06:25 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/31 11:41:02 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void		down_history(char **line, int line_length)
{
	char		*pos;
	t_linked	*next;

	if (g_history && g_history->next)
	{
		while (line_length)
		{
			pos = tgetstr("le", NULL);
			tputs(pos, 1, move_cursor);
			line_length--;
		}
		if (g_history->editing)
			g_history->cmd_tmp = *line;
		next = get_next();
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
			if (g_history_iter > 0)
				g_history_iter--;
			if (!g_history_iter)
				free_last();
		}
	}
}
