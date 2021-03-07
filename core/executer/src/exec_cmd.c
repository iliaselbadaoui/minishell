/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:31:34 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/07 12:34:19 by mait-si-         ###   ########.fr       */
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

static int		is_executable(t_string cmd_path, t_string *args)
{
	int	ret;

	ret = 1;
	if (open(cmd_path, O_RDONLY) <= 0) // Check the path to file is exist
	{
		ret = 0; // Failed
		free(cmd_path);
	}
	else if (!run_cmd(cmd_path, args)) // Run the Command
		ret = 0; // Failed
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
		return (echo(cmd->args, 1));
	else if (equals(cmd->args[0], "cd"))
		return (cd());
	else if (equals(cmd->args[0], "pwd"))
		return (pwd());
	else if (equals(cmd->args[0], "export"))
		return (export(cmd->args));
	else if (equals(cmd->args[0], "unset"))
		return (unset());
	else if (equals(cmd->args[0], "env"))
		return (env());
	return (0);
}

void			ft_freestrarr(char **arr)
{
	int i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	arr = NULL;
}

t_string		path_maker(t_string path, t_string arg)
{
	char		*half_path;
	char		*full_path;

	half_path = ft_strjoin(path, "/");
	full_path = ft_strjoin(half_path, arg);
	free(half_path);
	return (full_path);
}

int		check_bins(t_command *cmd)
{
	t_string	*path;
	int			i;
	int			ret;

	i = -1;
	ret = 0;
	if (cmd->args[0] && ft_strchr(cmd->args[0], '/'))
		return (is_executable(ft_strdup(cmd->args[0]), cmd->args));
	path = get_paths();
	while (path && path[++i])
	{
		ret = is_executable(path_maker(path[i], cmd->args[0]), cmd->args);
		if (ret == 1)
			break ;
	}
	ft_freestrarr(path);
	if (ret == 1)
		return (1);
	return (0);
}
