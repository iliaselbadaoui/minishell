/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:31:34 by mait-si-          #+#    #+#             */
/*   Updated: 2021/02/06 18:07:08 by mait-si-         ###   ########.fr       */
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
		free(path);
		out("Fork failed to create a new process.");
		return (-1);
	}
	wait(&pid);
	if (path)
		free(path);
	return (1);
}

// Checks if the command path is executable, then execute it.
// returns 1 if success, 0 if not
static int		is_executable(t_string cmd_path, t_command *cmd)
{
	// 1 - Check the path to file is exist
	if (open(cmd_path, O_RDONLY) <= 0)
		return (0);
	// 2 - Run the Command
	if (!run_cmd(cmd_path, cmd->args))
		return (0);
	return (1);
}

// Returns all the paths inside $PATH
// Still path variable has leaks
static t_string	*get_paths(void)
{
	t_map		*tmp;
	char		**path;
	int			i;

	tmp = g_map;
	path = NULL;
	i = -1;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, "PATH"))
		{
			path = ft_split(tmp->value, ':');
			break ;
		}
		tmp = tmp->next;
	}
	return (path);
}

int				check_builtins(t_command *cmd)
{
	if (!ft_strcmp(cmd->args[0], "exit"))
		return (-1);
	else if (!ft_strcmp(cmd->args[0], "echo"))
		return (echo(cmd->args));
	else if (!ft_strcmp(cmd->args[0], "cd"))
		return (cd());
	else if (!ft_strcmp(cmd->args[0], "pwd"))
		return (pwd());
	else if (!ft_strcmp(cmd->args[0], "export"))
		return (export());
	else if (!ft_strcmp(cmd->args[0], "unset"))
		return (unset());
	else if (!ft_strcmp(cmd->args[0], "env"))
		return (env());
	return (0);
}

int		check_bins(t_command *cmd)
{
	t_string	*path;
	int			i;

	i = 0;
	if (ft_strchr(cmd->args[0], '/'))
		return(is_executable(cmd->args[0], cmd));
	path = get_paths();
	while (path && path[++i])
		if (is_executable(ft_strjoin(ft_strjoin(path[i], "/"), cmd->args[0]), cmd))
			return (1);
	return (0);
}
