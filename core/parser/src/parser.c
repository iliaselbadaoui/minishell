/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:34:25 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/26 12:29:31 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

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
		pipes = spliter(commands[g_counter], '|');
		g_counter_extra=0;
		while (pipes[g_counter_extra])
		{
			add_command_to_end(&list, init_command(
			args_extracter(pipes[g_counter_extra]),
			redirections_extracter(pipes[g_counter_extra]), id));
			g_counter_extra++;
		}
		g_counter++;
		libre_2d(pipes);
		id++;
	}
	libre_2d(commands);
	return (list);
}
