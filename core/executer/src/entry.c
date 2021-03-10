/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:54:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/10 17:56:12 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		out("\nminishell$ ");
		signal(SIGINT, signal_handler);
	}
}

int		exec_cmd(t_command *cmd)
{
	int	ret;

	ret = 0;
	// Check builtins functions then check bins
	if ((ret = check_builtins(cmd)) == 1 || check_bins(cmd))
		return (0);
	if (ret == -1)
		return (-1);
	out("minishell$: ");
	out(cmd->args[0]);
	out(": command not found\n");
	return (CMMAND_NOT_FOUND);
}

int		exec_cmds(t_command *list)
{
	int		ret;

	ret = 0;
	while (list)
	{
		ret = exec_cmd(list);
		g_error = ret == -1 ? 1 : ret;
		if (ret == -1)
			return (-1);
		list = list->next;
	}
	// print_struct(list);
	return (ret);
}
