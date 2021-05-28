/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:48:58 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/28 16:59:06 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

static t_command	*get_cmd_positions(t_command *list)
{
	t_command	*tmp;
	int			id;

	id = list->id;
	tmp = list;
	tmp->pos = 1;
	tmp = tmp->next;
	while (tmp)
	{
		if (!tmp->next || tmp->next->id != id)
		{
			tmp->pos = 2;
			break ;
		}
		tmp->pos = 0;
		tmp = tmp->next;
	}
	return (list);
}

static void	dups(t_command *list, int input, int fds[2])
{
	if (list->pos == 1)
		dup2(fds[1], 1);
	else if (list->pos == 0)
	{
		dup2(input, 0);
		dup2(fds[1], 1);
	}
	else
		dup2(input, 0);
}

static int	close_all(int input, int fd1, int fd2, int position)
{
	if (input != 0)
		close(input);
	close(fd2);
	if (position == 2)
		close(fd1);
	input = fd1;
	return (input);
}

t_command	*handle_pipes(t_command *cmd)
{
	int			id;
	int			pid;
	t_command	*head;
	int			fds[2];
	int			input;

	head = cmd;
	id = cmd->id;
	cmd = get_cmd_positions(cmd);
	while (cmd)
	{
		pipe(fds);
		pid = fork();
		if (!pid)
		{
			dups(cmd, input, fds);
			exit(exec_command(cmd));
		}
		wait(&pid);
		input = close_all(input, fds[0], fds[1], cmd->pos);
		if (!cmd->next || cmd->next->id != id)
			break ;
		cmd = cmd->next;
	}
	return (cmd);
}
