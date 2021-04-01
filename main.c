/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 23:11:41 by ielbadao          #+#    #+#             */
/*   Updated: 2021/04/01 23:12:26 by ielbadao         ###   ########.fr       */
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
			}
			free(line);
			line = NULL;
			free_commands(&list);
			if (ret == -1)
				break ;
		}
	free_map(&g_map);
	return (0);
}
