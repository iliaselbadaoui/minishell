/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 23:11:41 by ielbadao          #+#    #+#             */
/*   Updated: 2021/04/08 10:12:38 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/executer/executer.h"
#include <string.h>
#include <stdio.h>

int		main(int argc, t_string *argv, t_string *envp)
{
	t_string	line;
	t_command	*list;
	int			ret;

	g_map = fill_env(envp);
	clone_env();
	init_caps();
	g_history_file = -1;
	if (argc && argv)
		while (1)
		{
			out("minishell$ ");
			// exit(1);
			line = readline();
			// signal(SIGINT, signal_handler);
			if (syntax_checker(trim(line)) && *line != '\0')
			{
				list = parser(trim(line));
				ret = exec_cmds(list);
				// ret = 0;
				// print_struct(list);
			}
			free(line);
			line = NULL;
			free_commands(&list);
			if (ret == -1) // Exit program with exit commant
				break ;
		}
	free_map(&g_map);
	free_map(&g_sorted_env);
	return (0);
}
