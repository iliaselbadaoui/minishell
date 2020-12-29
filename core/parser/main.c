/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:12:46 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/29 22:37:39 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <string.h>
#include <stdio.h>

int		main(int argc, t_string *argv, t_string *envp)
{
	t_string	line;
	t_command	*list;
	t_map	*map;

	map = fill_env(envp);
	if (argc && argv)
	{
		while (1)
		{
			out("minishell$ ");
			in(0, &line);
			if(syntax_checker(trim(line)))
			{
				list = parser(trim(line));
				t_command	*tmp = list;
				while (tmp)
				{
					printf("ARG |%s| id: %d\nFILE : [type: %c, file : %s]\n", tmp->args[0], tmp->id,(tmp->redirections)[0].type, (tmp->redirections)[0].file_name);
					tmp = tmp->next;
				}
			}
			free(line);
			free_commands(&list);
		}
	}
	free_map(&map);
	return (0);
}
