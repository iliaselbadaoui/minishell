/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 23:11:41 by ielbadao          #+#    #+#             */
/*   Updated: 2021/04/10 17:37:06 by mait-si-         ###   ########.fr       */
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

static void	loop(void)
{
	t_string	line;
	int			ret;
	t_command	*list;

	while (1)
	{
		out("minishell$ ");
		line = readline();
		if (syntax_checker(trim(line)) && *line != '\0')
		{
			list = parser(trim(line));
			// ret = exec_cmds(list);
			ret = 0;
			print_struct(list);
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
	g_map = fill_env(envp);
	clone_env();
	init_caps();
	g_history_file = -1;
	if (argc && argv)
		loop();
	free_map(&g_map);
	free_map(&g_sorted_env);
	return (0);
}
