/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:12:46 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/28 14:53:59 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <string.h>
#include <stdio.h>
//int argc, t_string *argv, t_string *envp
int		main()
{
	t_string	line;
	t_command	*list;
	
	while (1)
	{
		// args_extractor and redirection
		out("minishell$ ");
		in(0, &line);
		list = parser(trim(line));
		t_command	*tmp = list;
		while (tmp)
		{
			printf("ARG |%s| id: %d\nFILE : [type: %c, file : %s]\n", tmp->args[0], tmp->id,(tmp->redirections)[0].type, (tmp->redirections)[0].file_name);
			tmp = tmp->next;
		}
		free(line);
		free_commands(&list);
	}
	return (0);
}
