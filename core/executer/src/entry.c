/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:54:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/19 23:55:59 by 0x10000          ###   ########.fr       */
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
	int	i;

	ret = 0;
	i = -1;
	// Filter Commands, ex: "echo" => echo
	// cmd->args[0] = filter(cmd->args[0]);
	// Check builtins functions then check bins
	if ((ret = check_builtins(cmd)) == 1)
		return (0);
	else if (check_bins(cmd))
		return (0);
	if (ret == -1)
		return (-1);
	printf("minishell$: %s: command not found\n", cmd->args[0]);
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
	return (ret);
}
