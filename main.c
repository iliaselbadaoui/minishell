/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:50:26 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/22 14:48:17 by 0x10000          ###   ########.fr       */
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
	if (argc && argv)
		while (1)
		{
			history();
			out("minishell$ ");
			in(0, &line);
			// signal(SIGINT, signal_handler);
			if (syntax_checker(trim(line)) && *line != '\0')
			{
				list = parser(trim(line));
				ret = exec_cmds(list);
			}
			free(line);
			free_commands(&list);
			if (ret == -1) // Exit program with exit commant
				break ;
		}
	free_map(&g_map);
	free_map(&g_sorted_env);
	return (0);
}
