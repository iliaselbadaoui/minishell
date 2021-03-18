/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:54:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/18 19:21:58 by mait-si-         ###   ########.fr       */
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
	// Filter Commands
	while (cmd->args[++i])
		cmd->args[i] = filter(cmd->args[i]);
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
	// print_struct(list);
	return (ret);
}
