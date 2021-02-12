/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:31:34 by mait-si-          #+#    #+#             */
/*   Updated: 2021/02/12 14:25:14 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

int				run_cmd(t_string path, t_string *args)
{
	pid_t	pid;

	pid = fork();
	// signal(SIGINT, signal_handler);
	if (pid == 0)
		execve(path, args, g_envp);
	else if (pid < 0)
	{
		// Child Process
		free(path);
		out("Fork failed to create a new process.");
		return (-1);
	}
	wait(&pid);
	if (path)
		free(path);
	return (1);
}

static int		is_executable(t_string cmd_path, t_command *cmd)
{
	int	ret;

	ret = 1;
	if (open(cmd_path, O_RDONLY) <= 0) // Check the path to file is exist
		ret = 0; // Failed
	else if (!run_cmd(cmd_path, cmd->args)) // Run the Command
		ret = 0; // Failed
	// free(cmd_path);
	// cmd_path = NULL;
	return (ret); // Successed
}

// Returns all programs path from $PATH
static t_string	*get_paths(void)
{
	t_map		*tmp;
	t_string	*path;

	tmp = g_map;
	path = ft_split(get_value_by_key(tmp, "PATH"), ':');
	return (path);
}

// Check is the command builtin
int				check_builtins(t_command *cmd)
{
	if (equals(cmd->args[0], "exit"))
		return (exit_shell(cmd));
	else if (equals(cmd->args[0], "echo"))
		return (echo(cmd->args));
	else if (equals(cmd->args[0], "cd"))
		return (cd());
	else if (equals(cmd->args[0], "pwd"))
		return (pwd());
	else if (equals(cmd->args[0], "export"))
		return (export());
	else if (equals(cmd->args[0], "unset"))
		return (unset());
	else if (equals(cmd->args[0], "env"))
		return (env());
	return (0);
}

int		check_bins(t_command *cmd)
{
	t_string	*path;
	int			i;
	int			ret;

	i = -1;
	ret = 0;
	if (cmd->args[0] && ft_strchr(cmd->args[0], '/'))
		return(is_executable(cmd->args[0], cmd));
	path = get_paths();
	while (path && path[++i])
	{
		ret = is_executable(ft_strjoin(ft_strjoin(path[i], "/"), cmd->args[0]), cmd);
		free(path[i]);
		path[i] = NULL;
		if (ret == 1)
			break ;
	}
	// free(path[i]);
	if (ret == 1)
		return (1);
	return (0);
}
