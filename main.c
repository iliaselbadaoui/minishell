/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 00:28:25 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 00:41:02 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/executer/executer.h"
#include <string.h>
#include <stdio.h>

static void	exit_minishell(void)
{
	free_map(&g_container->map);
	free_map(&g_container->sorted_env);
	exit(g_container->error);
}

static void	loop(void)
{
	t_string	line;
	int			ret;
	t_command	*list;

	while (1)
	{
		out("\033[32mminishell$ \033[37m");
		signal(SIGINT, signal_handler);
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

int		main(int argc, t_string *argv, t_string *envp)
{
	g_container = (t_container *)malloc(sizeof(t_container));
	g_container->map = fill_env(envp);
	clone_env();
	init_caps();
	g_container->history_file = -1;
	if (argc && argv)
		loop();
	free_map(&g_container->map);
	free_map(&g_container->sorted_env);
	return (0);
}
