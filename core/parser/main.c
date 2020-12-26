/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:12:46 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/26 19:03:09 by ielbadao         ###   ########.fr       */
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
		list = parser(line);
		t_command	*tmp = list;
		while (tmp)
		{
			printf("%s\n", tmp->args[0]);
			tmp=tmp->next;
		}
		free(line);
		free_commands(&list);
	}
	
	return (0);
}
