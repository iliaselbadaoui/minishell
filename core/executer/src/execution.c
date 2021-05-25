/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:33:07 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/23 20:33:48 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

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

// Check is the command builtin
static int	check_builtins(t_command *cmd)
{
	if (equals(cmd->args[0], "exit"))
		return (exit_shell(cmd));			// returns: -1 with SUCCESS, 1 with Failure & without exitting, 255: exit with Failure
	else if (equals(cmd->args[0], "echo"))
		return (echo(cmd->args));			// returns: 0 with SUCCESS
	else if (equals(cmd->args[0], "cd"))
		return (cd(cmd->args));				// returns: 0 with SUCCESS, 1 with Failure
	else if (equals(cmd->args[0], "pwd"))
		return (pwd());						// returns: 0 with SUCCESS, 1 with Failure
	else if (equals(cmd->args[0], "export"))
		return (export(cmd->args));			// returns: 0 with SUCCESS, 1 with Failure
	else if (equals(cmd->args[0], "unset"))
		return (unset(cmd->args));			// returns: 0 with SUCCESS, 1 with Failure
	else if (equals(cmd->args[0], "env"))
		return (env());						// returns: 0 with SUCCESS, 1 with Failure
	return (2);								// Not a builtin command
}

// Execute a single command
int	execution(t_command *list, t_string cmd)
{
	int	ret;
	int	i;

	ret = 0;
	i = -1;
	if (!cmd)
		return (0);
	if (cmd[0] != '\0')
	{
		ret = check_builtins(list);			// Check builtins functions, if return is 2, the command not in builtins
		if (ret != 2)
			return (ret);
		if (get_env_value("PATH")[0] == '\0')	// Check if PATH variable is not empty && is exist
			ret = 2;
		else
		{
			ret = check_bins(list);				// Check Command file if PATH variable exist
			if (ret != 2 && ret != 127)
				return (ret);
		}
		if (ret == 2)
			return (no_file_directory(cmd));
	}
	return (command_not_found(cmd));
}

int	exec_command(t_command *list)
{
	int			ret;
	int			fd_in;
	int			fd_out;

	ret = 0;
	if (list->redirections->file_name)
	{
		fd_in = dup(0);
		fd_out = dup(1);
	}
	// Redirection Checker
	if (list->redirections->file_name)
		if (check_redirection(list))
			return (EXIT_FAILURE);
	// Execution
	ret = execution(list, list->args[0]);
	ret = get_error(ret);
	if (list->redirections->file_name)
	{
		dup2(fd_in, 0);
		dup2(fd_out, 1);
		close(fd_in);
		close(fd_out);
	}
	return (ret);
}
