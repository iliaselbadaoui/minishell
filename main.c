/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:12:46 by ielbadao          #+#    #+#             */
/*   Updated: 2021/01/30 16:44:48 by 0x10000          ###   ########.fr       */
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
			in(0, &line);
			if (syntax_checker(trim(line)))
			{
				list = parser(trim(line));
				execute(list);
			}
			free(line);
			free_commands(&list);
		}
	}
	free_map(&map);
	return (0);
}
