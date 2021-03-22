/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:31:34 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/22 15:10:39 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

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

// Ecexute file if exist, ex: /bin/ls
static int			execute(t_string path, t_string *args)
{
	int	ret;

	ret = 0;
	// Check the file if not exist
	if (open(path, O_RDONLY) <= 0)
		ret = 1; // the path to the file not exist
	// Run the Command
	else if (run_cmd(path, args))
		ret = 1; // Failed
	free(path);
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
		return (execute(ft_strdup(cmd->args[0]), cmd->args));
	// Run the command with its name, using PATH variable, ex: ls will executed as /bin/ls
	if (!(path = get_paths()))
	{
		write(2, "minishell: ", 11);
		write(2, cmd->args[0], length(cmd->args[0]));
		write(2, ": No such file or directory\n", 28);
		return (CMMAND_NOT_FOUND);
	}
	while (path[++i])
	{
		ret = execute(path_maker(path[i], cmd->args[0]), cmd->args);
		if (ret == 0)
			break ;
	}
	free(path);
	path = NULL;
	return (ret);
}
