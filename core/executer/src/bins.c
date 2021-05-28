/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bins.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:23:54 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/28 16:13:31 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

// Returns all paths from PATH environment variable
static t_string	*get_paths(void)
{
	t_map		*tmp;
	t_string	*path;

	tmp = g_container->map;
	path = ft_split(get_value_by_key(tmp, "PATH"), ':');
	return (path);
}

// Make an absolute Path, ex: /bin + ls = /bin/ls
static t_string	path_maker(t_string path, t_string cmd)
{
	char		*half_path;
	char		*full_path;

	half_path = ft_strjoin(path, "/");
	full_path = ft_strjoin(half_path, cmd);
	free(half_path);
	return (full_path);
}

// Run the command if exist
static int	run_cmd(t_string path, t_string *args)
{
	pid_t		pid;
	int			ret;

	pid = fork();
	ret = 0;
	if (++g_container->is_process && pid == 0) // Child Process
	{
		if (execve(path, args, g_container->envp) == -1)
			ret = 1;
		else
			ret = 0;
	}
	else if (pid < 0)
	{
		write(2, "Fork failed to create a new process.", 36);
		return (1);
	}
	wait(&pid); // Wait for the child to finish
	g_container->is_process = 0;
	return (ret);
}

// Ecexute file if exist, ex: /bin/ls
static int	execute(t_string path, t_string *args)
{
	int	ret;

	ret = 0;
	// Check the file if not exist
	if (open(path, O_RDONLY) <= 0)
	{
		free(path);
		return (CMMAND_NOT_FOUND); // the path to the file not exist
	}
	// Run the Command
	else
	{
		ret = run_cmd(path, args);
		if (ret)
		{
			free(path);
			return (ret); // Failed
		}
	}
	free(path);
	return (ret); // Successed
}

// Check if the command in bins
int	check_bins(t_command *cmd)
{
	t_string	*path;
	t_string	tmp_path;
	int			i;
	int			ret;

	i = -1;
	ret = 0;
	// Run the command with a given relative path, ex: ./minishell
	if (cmd->args[0][0] == '.')
	{
		tmp_path = ft_strjoin(getcwd(NULL, 0), "/");
		ret = execute(ft_strjoin(tmp_path, cmd->args[0]), cmd->args);
		free(tmp_path);
		if (ret == 127)
			ret = 2;
		return (ret);
	}
	// Run the command with a given absolute path, ex: /bin/ls
	if (cmd->args[0][0] == '/')
	{
		ret = execute(ft_strdup(cmd->args[0]), cmd->args);
		if (ret == 127)
			ret = 2;
		return (ret);
	}
	// Run the command with its name, using PATH variable, ex: ls will executed as /bin/ls
	path = get_paths();
	if (!path)
		return (2);
	while (path[++i])
	{
		ret = execute(path_maker(path[i], cmd->args[0]), cmd->args);
		if (!ret) // if execution SUCCED
			break ;
	}
	free_2d_arr(path);
	return (ret);
}
