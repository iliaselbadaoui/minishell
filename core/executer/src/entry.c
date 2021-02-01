/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:54:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/02/01 12:55:27 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

t_bool	is_cmd(t_string cmd)
{
	if (!ft_strcmp(cmd, "echo") ||
		!ft_strcmp(cmd, "cd") ||
		!ft_strcmp(cmd, "pwd") ||
		!ft_strcmp(cmd, "export") ||
		!ft_strcmp(cmd, "unset") ||
		!ft_strcmp(cmd, "env") ||
		!ft_strcmp(cmd, "exit"))
		return (true);
	return (false);
}

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		out("\nminishell$ ");
		signal(SIGINT, signal_handler);
	}
}

void	print_struct(t_command *list)
{
	int i;

	while (list)
	{
		// printf("\n__________________________\n");
		// printf("\nID: [%d]\n", list->id);
		out("cmd:\t");
		out(list->args[0]);
		out("\nargs:\t");
		i = 1;
		while (list->args[i])
		{
			out(list->args[i++]);
			out("   ");
		}
		out("\n");
		// printf("\ntype: [%c]", list->redirections->type);
		// printf("\nfd: [%d]", list->redirections->fd);
		// printf("\nfile_name: [%s]", list->redirections->file_name);
		// printf("\n__________________________\n");
		list = list->next;
	}
}

int		exec_cmds(t_command *list)
{
	if (list)
		if (!is_cmd(list->args[0]))
		{
			out("minishell: ");
			out(list->args[0]);
			out(": command not found\n");
			return (0);
		}
	print_struct(list);
	return (0);
}
