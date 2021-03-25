/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:31:34 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/25 13:19:44 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

// Returns all paths from PATH environment variable
static t_string		*get_paths(void)
{
	t_map		*tmp;
	t_string	*path;

	tmp = g_map;
	path = ft_split(get_value_by_key(tmp, "PATH"), ':');
	return (path);
}

// Make an absolute Path, ex: /bin + ls = /bin/ls
static t_string		path_maker(t_string path, t_string cmd)
{
	char		*half_path;
	char		*full_path;

	half_path = ft_strjoin(path, "/");
	full_path = ft_strjoin(half_path, cmd);
	free(half_path);
	return (full_path);
}

// Run the command if exist
static int			run_cmd(t_string path, t_string *args)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	ret = 0;
	// signal(SIGINT, signal_handler);
	if (pid == 0) // Child Process
		ret = execve(path, args, g_envp) == -1 ? 1 : 0;
	else if (pid < 0)
	{
		write(2, "Fork failed to create a new process." , 36);
		return (1);
	}
	wait(&pid); // Wait for the child to finish
	return (ret);
}

// Ecexute file if exist, ex: /bin/ls
static int			execute(t_string path, t_string *args)
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
	else if ((ret = run_cmd(path, args)))
	{
		free(path);
		return (ret); // Failed
	}
	return (ret); // Successed
}

// Check if the command in bins
int					check_bins(t_command *cmd)
{
	t_string	*path;
	int			i;
	int			ret;

	i = -1;
	ret = 0;
	// Run the command with a given absolute path, ex: /bin/ls
	if (cmd->args[0] && ft_strchr(cmd->args[0], '/'))
	{
		ret = execute(ft_strdup(cmd->args[0]), cmd->args);
		return (ret == 127 ? 2 : ret);
	}
	// Run the command with its name, using PATH variable, ex: ls will executed as /bin/ls
	if (!(path = get_paths()))
		return (2);
	while (path[++i])
		if (!(ret = execute(path_maker(path[i], cmd->args[0]), cmd->args))) // if execution succed
			break ;
	free(path);
	path = NULL;
	return (ret);
}
