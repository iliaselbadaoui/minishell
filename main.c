/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:26:09 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/22 14:42:59 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/executer/executer.h"
#include <string.h>
#include <stdio.h>

static void	exit_minishell(void)
{
	free_map(&g_map);
	free_map(&g_sorted_env);
	exit(g_error);
}

int		main(int argc, t_string *argv, t_string *envp)
{
	t_string	line;
	int			ret;
	t_command	*list;

	g_map = fill_env(envp);
	clone_env();
	init_caps();
	g_history_file = -1;
	if (argc && argv)
	{
		while (1)
		{
			out("\033[32mminishell$ \033[37m");
			line = readline();
			if (syntax_checker(trim(line)) && *line != '\0')
			{
				list = parser(trim(line));
				ret = exec_cmds(list);
			}
			free(line);
			line = NULL;
			free_commands(&list);
			if (ret == -1)
				exit_minishell();
		}
	}
	free_map(&g_map);
	free_map(&g_sorted_env);
	return (0);
}
