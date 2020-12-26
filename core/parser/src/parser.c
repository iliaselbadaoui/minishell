/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:34:25 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/26 19:13:52 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static void		help(t_command **list, t_string *pipes, int id)
{
	add_command_to_end(list, init_command(
	args_extracter(pipes[g_counter_extra]),
	NULL, id));
	g_counter_extra++;
}

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
			help(&list, pipes, id);
		libre_2d(pipes);
		id++;
		g_counter++;
	}
	printf("HELLO\n");
	id = 0;
	libre_2d(commands);
	return (list);
}
