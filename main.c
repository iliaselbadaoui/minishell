/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:12:46 by ielbadao          #+#    #+#             */
/*   Updated: 2021/01/31 18:55:53 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/executer/executer.h"
#include <string.h>
#include <stdio.h>

int		main(int argc, t_string *argv, t_string *envp)
{
	t_string	line;
	t_command	*list;
	t_map		*map;

	map = fill_env(envp);
	if (argc && argv)
	{
		while (1)
		{
			out("minishell$ ");
			signal(SIGINT, signal_handler);
			in(0, &line);
			if (syntax_checker(trim(line)))
			{
				list = parser(trim(line));
				if (!execute(list))
					continue ;
			}
			free(line);
			free_commands(&list);
		}
	}
	free_map(&map);
	return (0);
}
