/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:53:46 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/25 16:39:08 by ielbadao         ###   ########.fr       */
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

	list = NULL;
	while (1)
	{
		out("\033[32mminishell$ \033[37m");
		signal(SIGINT, signal_handler);
		line = readline();
		if (syntax_checker(trim(line)) && *line != '\0')
		{
			list = parser(trim(line));
			ret = entry(list);
		}
		free(line);
		line = NULL;
		free_commands(&list);
		if (ret == -1)
			exit_minishell();
	}
}
static void	container_init(void)
{
	g_container = (t_container *)malloc(sizeof(t_container));
	g_container->envp = NULL;
	g_container->envp_count = 0;
	g_container->flag = 0;
	g_container->error = 0;
	g_container->map_fill_first_time = 0;
	g_container->counter = 0;
	g_container->args_counter = 0;
	g_container->counter_extra = 0;
	g_container->spliter_counter = 0;
	g_container->spliter_char = 0;
	g_container->gchar = 0;
	g_container->history_file = 0;
	g_container->history_iter = 0;
	g_container->last = NULL;
	g_container->history = NULL;
	g_container->history_to_free = NULL;
	g_container->history_the_oldest = NULL;
	g_container->map = NULL;
	g_container->sorted_env = NULL;
}
int	main(int argc, t_string *argv, t_string *envp)
{
	container_init();
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
