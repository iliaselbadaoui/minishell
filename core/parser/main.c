/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:12:46 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/26 12:27:17 by ielbadao         ###   ########.fr       */
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
		out("minishell$ ");
		in(0, &line);
		if (syntax_checker(trim(line)))
		{
			list = parser(line);
			// t_command *tmp = list;
			// while (tmp)
			// {
			// 	printf("id : %d, command: %s, redirection0 : %s\n", tmp->id, tmp->args[0], (tmp->redirections)[0].file_name);
			// 	tmp = tmp->next;
			// }
			
		}
		free_commands(&list);
		free(line);
		line = NULL;
	}
	return (0);
}
