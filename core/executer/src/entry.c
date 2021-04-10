/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:54:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/04/10 17:33:39 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

// Check is the command builtin
static int	check_builtins(t_command *cmd)
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

static int	no_file_directory(t_string cmd)
{
	write(2, "minishell: ", 11);
	write(2, cmd, length(cmd));
	write(2, ": No such file or directory\n", 28);
	return (CMMAND_NOT_FOUND);
}

static int	command_not_found(t_string cmd)
{
	printf("minishell$: %s: command not found\n", cmd);
	return (CMMAND_NOT_FOUND);
}

// Execute a command.
static int	exec_cmd(t_command *list, t_string *cmd)
{
	int	ret;
	int	i;

	ret = 0;
	i = -1;
	if (!*cmd)
		return (0);
	*cmd = filter(ft_strdup(*cmd)); // Filter The Command, ex: "echo" => echo
	if (*cmd[0] != '\0')
	{
		ret = check_builtins(list); // Check builtins functions, if return is 2, the command not in builtins
		if (ret != 2)
			return (ret);
		if (get_env_value("PATH")[0] == '\0') // Check if PATH variable is not empty && is exist
			ret = 2;
		else
		{
			ret = check_bins(list); // Check Command file if PATH variable exist
			if (ret != 2 && ret != 127)
				return (ret);
		}
		if (ret == 2)
			return (no_file_directory(*cmd));
	}
	return (command_not_found(*cmd));
}

// Execute all commands, separated by ";"
// return 0, -1 : SUCCESS
// return 1, 127, 255, ... : FAILED
int	exec_cmds(t_command *list)
{
	int			ret;
	t_string	cmd;

	ret = 0;
	while (list)
	{
		cmd = list->args[0];
		ret = exec_cmd(list, &cmd);
		free(cmd);
		g_error = ret;
		if (ret == -1)
			g_error = 0;
		if (ret == 255)
		{
			ret = -1;
			g_error = 255;
		}
		// printf("ng_error: [%d]\n", g_error);
		list = list->next;
	}
	return (ret);
}
