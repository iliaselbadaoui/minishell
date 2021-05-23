/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:34:25 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 12:46:10 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static void	help(t_command **list, t_string *pipes, int id)
{
	t_string	trimed;

	trimed = ft_strdup(trim(pipes[g_container->counter_extra]));
	add_command_to_end(list,
		init_command(args_extracter(trimed),
			redirections_extracter(trimed), id));
	free(trimed);
	g_container->counter_extra++;
}

t_command	*parser(t_string line)
{
	t_string	*commands;
	t_string	*pipes;
	static int	id;
	int			counter;
	t_command	*list;

	if (!line)
		return (NULL);
	commands = spliter(line, ';');
	list = NULL;
	counter = 0;
	while (commands[counter])
	{
		g_container->counter_extra = 0;
		pipes = spliter(trim(commands[counter]), '|');
		while (pipes[g_container->counter_extra])
			help(&list, pipes, id);
		id++;
		counter++;
		libre_2d(pipes);
	}
	id = 0;
	libre_2d(commands);
	return (list);
}
