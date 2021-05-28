/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:53:09 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/28 16:47:14 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

static int	no_file_directory(t_string cmd)
{
	write(2, "minishell: ", 11);
	write(2, cmd, length(cmd));
	write(2, ": No such file or directory\n", 28);
	return (1);
}

static void	create_files(char type, t_string file_name)
{
	if (type == 'c')
		close(open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666));
	else if (type == 'a')
		close(open(file_name, O_RDWR | O_CREAT | O_APPEND, 0666));
}

static int	open_file(char type, t_string file_name)
{
	if (type == 'c')
		return (open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644));
	else if (type == 'a')
		return (open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644));
	return (1);
}

static t_redirect	**get_files(t_command *list, int *ret)
{
	int			tmp;
	t_redirect	**files;
	t_redirect	*red;

	files = (t_redirect **)ft_calloc(2, sizeof(t_redirect *));
	red = list->redirections;
	while (red->file_name)
	{
		create_files(red->type, red->file_name);
		if (red->type == 'c' || red->type == 'a')
			files[0] = red;
		else if (red->type == 'r')
		{
			tmp = open(red->file_name, O_RDONLY, 0666);
			close(tmp);
			if (tmp == -1)
			{
				*ret = no_file_directory(red->file_name);
				break ;
			}
			files[1] = red;
		}
		red++;
	}
	return (files);
}

int	check_redirection(t_command *list)
{
	int			fd_stdin;
	int			fd_stdout;
	t_redirect	**files;
	int			ret;

	files = get_files(list, &ret);
	if (ret == 1)
		return (EXIT_FAILURE);
	if (files[0])
	{
		fd_stdout = open_file(files[0]->type, files[0]->file_name);
		dup2(fd_stdout, STDOUT_FILENO);
		close(fd_stdout);
	}
	if (files[1])
	{
		fd_stdin = open(files[1]->file_name, O_RDONLY, 0666);
		dup2(fd_stdin, STDIN_FILENO);
		close(fd_stdin);
	}
	free(files);
	return (EXIT_SUCCESS);
}
