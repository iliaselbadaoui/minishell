/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:12:46 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/25 18:57:45 by mait-si-         ###   ########.fr       */
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
