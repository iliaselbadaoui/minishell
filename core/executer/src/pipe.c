/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:48:58 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/21 23:58:46 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

static t_command *get_cmd_positions(t_command *list)
{
	t_command	*tmp;
	int			id;

	id = list->id;
	tmp = list;
	// first node
	tmp->pos = 1;
	tmp = tmp->next;
	while(tmp)
	{
		// last node
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
	if (list->pos == 1)			// first cmd
		dup2(fds[1], 1);
	else if (list->pos == 0)	// middle cmds
	{
		dup2(input, 0);
		dup2(fds[1], 1);
	}
	else						// last cmd
		dup2(input, 0);
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
	// Loop through pipe line (separated by | )
	while (cmd)
	{
		pipe(fds);
		pid = fork();
		if (!pid)
		{
			/* Child */
			// Duplicate pipes file descriptors with STDs
			dups(cmd, input, fds);
			// Execute the command to pip fd with exit return on child process
			exit(exec_command(cmd));
		}
		// Wait the child till finish
		wait(&pid);
		if (input != 0)
			close(input);
		close(fds[1]);
		if (cmd->pos == 2)
			close(fds[0]);
		input = fds[0];
		if (!cmd->next || cmd->next->id != id)
			break;
		cmd = cmd->next;
	}
	return (cmd);
}
