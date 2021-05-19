/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:53:09 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/07 20:53:12 by 0x10000          ###   ########.fr       */
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

static t_redirect	**get_files(t_command *list, int *ret)
{
	int			tmp;
	t_redirect	**files;
	t_redirect	*red;

	files = (t_redirect**)ft_calloc(2, sizeof(t_redirect*));
	red = list->redirections;
	// Loop through redirections
	while (red->file_name)
	{
		if (red->type == 'c')		// >
			close(open(red->file_name, O_RDWR|O_CREAT|O_TRUNC, 0666));
		else if (red->type == 'a')	// >>
			close(open(red->file_name, O_RDWR|O_CREAT|O_APPEND, 0666));
		if (red->type == 'c' || red->type == 'a')
			files[0] = red;
		else if (red->type == 'r')	// <
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

	// Get last file on >, >> and <.
	// Meanwhile create the output files and check the input files if exist
	files = get_files(list, &ret);
	if (ret == 1)
		return (EXIT_FAILURE); // an input file dosen't exist
	fd_stdout = 1;
	if (files[0])
	{
		if (files[0]->type == 'c')			// >
			fd_stdout = open(files[0]->file_name, O_WRONLY|O_CREAT|O_TRUNC, 0644);
		else if (files[0]->type == 'a')	// >>
			fd_stdout = open(files[0]->file_name, O_WRONLY|O_CREAT|O_APPEND, 0644);
		// Duplicating file descriptors
		dup2(fd_stdout, STDOUT_FILENO);
		close(fd_stdout);
	}
	if (files[1])
	{
		fd_stdin = open(files[1]->file_name, O_RDONLY, 0666);
		// Duplicating file descriptors
		dup2(fd_stdin, STDIN_FILENO);
		close(fd_stdin);
	}
	free(files);
	return (EXIT_SUCCESS); //SUCCESS
}
