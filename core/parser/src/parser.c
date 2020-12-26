/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:34:25 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/26 16:01:58 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

// static void		help(t_command **list, t_string *pipes, int id)
// {
// 	add_command_to_end(list, init_command(
// 	args_extracter(pipes[g_counter_extra]),
// 	redirections_extracter(pipes[g_counter_extra]), id));
// 	g_counter_extra++;
// }

t_command		*parser(t_string line)
{
	t_string	*commands;
	t_string	*pipes;
	static int	id;
	t_command	*list;

	commands = spliter(line, ';');
	list = NULL;
	g_counter = 0;
	while (commands[g_counter])
	{
		g_counter_extra=0;
		pipes = spliter(commands[g_counter], '|');
		while (pipes[g_counter_extra])
		{	
			printf("%s\n", pipes[g_counter_extra]);
			g_counter_extra++;
		}
		libre_2d(pipes);
		printf("FUCK\n");
		id++;
		g_counter++;
	}
	id = 0;
	libre_2d(commands);
	return (list);
}
