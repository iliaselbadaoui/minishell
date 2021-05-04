/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:54:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/04 13:33:32 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

// Check is the command builtin
static int	check_builtins(t_command *cmd, int fd)
{
	if (equals(cmd->args[0], "exit"))
		return (exit_shell(cmd));		// returns: -1 with SUCCESS, 1 with Failure & without exitting, 255: exit with Failure
	else if (equals(cmd->args[0], "echo"))
		return (echo(cmd->args, fd));	// returns: 0 with SUCCESS
	else if (equals(cmd->args[0], "cd"))
		return (cd(cmd->args));			// returns: 0 with SUCCESS, 1 with Failure
	else if (equals(cmd->args[0], "pwd"))
		return (pwd(fd));				// returns: 0 with SUCCESS, 1 with Failure
	else if (equals(cmd->args[0], "export"))
		return (export(cmd->args, fd));	// returns: 0 with SUCCESS, 1 with Failure
	else if (equals(cmd->args[0], "unset"))
		return (unset(cmd->args));		// returns: 0 with SUCCESS, 1 with Failure
	else if (equals(cmd->args[0], "env"))
		return (env(fd));				// returns: 0 with SUCCESS, 1 with Failure
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
static int	exec_cmd(t_command *list, t_string *cmd, int fd)
{
	int	ret;
	int	i;

	ret = 0;
	i = -1;
	if (!*cmd)
		return (0);
	*cmd = filter(ft_strdup(*cmd));				// Filter The Command, ex: "echo" => echo
	if (*cmd[0] != '\0')
	{
		ret = check_builtins(list, fd);			// Check builtins functions, if return is 2, the command not in builtins
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
	int			fd_out;
	int			fd_in;

	ret = 0;
	fd_in = dup(0);
	fd_out = dup(1);
	while (list)
	{
		// Redirection Checker
		if (list->redirections->file_name)
			if (check_redirection(list) == 1)
			{
				ret = 1;
				list = list->next;
				continue ;
			}

		// Execution
		cmd = list->args[0];
		ret = exec_cmd(list, &cmd, 1);
		free(cmd);
		ret = get_error(ret);

		// Duplicating file descriptors
		if (list->redirections->file_name)
		{
			dup2(fd_in, 0);
			dup2(fd_out, 1);
		}
		list = list->next;
	}
	return (ret);
}
