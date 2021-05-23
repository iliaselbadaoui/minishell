/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:08:52 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 12:37:18 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static void	save_history(void)
{
	t_linked	*tmp;

	g_container->history_file = open(".history", O_RDWR | O_CREAT, 0666);
	tmp = g_container->history_the_oldest;
	while (tmp)
	{
		write(g_container->history_file, tmp->cmd, ft_strlen(tmp->cmd));
		write(g_container->history_file, "\n", 1);
		tmp = tmp->next;
	}
	close(g_container->history_file);
}

void	newline(char *line, int *done)
{
	t_linked	*tmp;

	if (g_container->history && g_container->history_iter)
	{
		while (g_container->history->next && g_container->history->already)
			g_container->history = g_container->history->next;
		free_last();
		tmp = g_container->history_the_oldest;
		while (tmp)
		{
			tmp->editing = 0;
			tmp = tmp->next;
		}
	}
	g_container->last = NULL;
	if (*line != '\0' && line != NULL)
		add_node(line, 1);
	*done = 0;
	write_to_stdout("\n");
	g_container->history_iter = 0;
	save_history();
}
