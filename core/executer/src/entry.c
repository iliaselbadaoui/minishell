/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:54:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/22 14:57:57 by 0x10000          ###   ########.fr       */
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

// Check is the command builtin
int		check_builtins(t_command *cmd)
{
	if (equals(cmd->args[0], "exit"))
		return (exit_shell(cmd));		// returns: -1 with SUCCESS, 1 with Failure & without exitting, 255: exit with Failure
	else if (equals(cmd->args[0], "echo"))
		return (echo(cmd->args, 1));	// returns: 0 with SUCCESS
	else if (equals(cmd->args[0], "cd"))
		return (cd(cmd->args));			// returns: 0 with SUCCESS, 1 with Failure
	else if (equals(cmd->args[0], "pwd"))
		return (pwd(1));				// returns: 0 with SUCCESS, 1 with Failure
	else if (equals(cmd->args[0], "export"))
		return (export(cmd->args, 1));	// returns: 0 with SUCCESS, 1 with Failure
	else if (equals(cmd->args[0], "unset"))
		return (unset(cmd->args));		// returns: 0 with SUCCESS, 1 with Failure
	else if (equals(cmd->args[0], "env"))
		return (env(1));				// returns: 0 with SUCCESS, 1 with Failure
	return (2);							// Not a builtin command
}

// Execute a command.
int		exec_cmd(t_command *cmd)
{
	int	ret;
	int	i;

	ret = 0;
	i = -1;
	cmd->args[0] = filter(cmd->args[0]); // Filter The Command, ex: "echo" => echo
	if (cmd->args[0][0] != '\0')
	{
		if ((ret = check_builtins(cmd)) != 2) // Check builtins functions
			return (ret);
		else if ((ret = check_bins(cmd)))
			return (ret);
	}
	printf("minishell$: %s: command not found\n", cmd->args[0]);
	return (CMMAND_NOT_FOUND);
}

// Execute all commands, separated by ";"
int		exec_cmds(t_command *list)
{
	int	ret;

	ret = 0;
	while (list)
	{
		ret = exec_cmd(list);
		g_error = ret;
		if (ret == -1)
			g_error = 0;
		if (ret == 255)
		{
			ret = -1;
			g_error = 255;
		}
		printf("\ng_error: [%d]\n", g_error);
		list = list->next;
	}
	// return 0, -1 : SUCCESS
	// return 1, 127, 255, ... : FAILED
	return (ret);
}
