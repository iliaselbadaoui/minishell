/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:08:52 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/31 11:41:02 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static void	save_history()
{
	t_linked	*tmp;
	
	g_history_file = open(".history", O_RDWR|O_CREAT, 0666);
	tmp = g_history_the_oldest;
	while (tmp)
	{
		write(g_history_file, tmp->cmd, ft_strlen(tmp->cmd));
		write(g_history_file, "\n", 1);
		tmp = tmp->next;
	}
	close(g_history_file);
}

void		newline(char	*line, int *done)
{
	t_linked	*tmp;

	if (g_history && g_history_iter)
	{
		while (g_history->next && g_history->already)
			g_history = g_history->next;
		free_last();
		tmp = g_history_the_oldest;
		while (tmp)
		{
			tmp->editing = 0;
			tmp = tmp->next;
		}
	}
	g_last = NULL;
	if (*line != '\0' && line != NULL)
		add_node(line, 1);
	*done = 0;
	write_to_stdout("\n");
	g_history_iter = 0;
	save_history();
}
