/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:50:26 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/18 12:50:46 by ielbadao         ###   ########.fr       */
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
	if (argc && argv)
		while (1)
		{
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
			if (ret == -1)
				break ;
		}
	free_map(&g_map);
	return (0);
}
