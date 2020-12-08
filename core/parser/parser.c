/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 15:29:09 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/08 11:36:49 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_part		*parser(char *line)
{
	t_part	*cmd;
	char	**pipe;
	char	**commands;
	char	**commands_tmp;
	char	**pipe_tmp;

	if (!line)
		return (NULL);
	cmd = NULL;
	pipe = pipes(line);
	pipe_tmp = pipe;
	while (*pipe)
	{
		commands = parts(*pipe);
		commands_tmp = commands;
		while (*commands)
		{
			// ft_printf("PIPE %d (%s)\n", g_pipe_id, *commands);
			add_part(&cmd, sequencer(*commands, g_pipe_id));
			commands++;
		}
		free_double_char_arr(commands_tmp);
		pipe++;
		g_pipe_id++;
	}
	free_double_char_arr(pipe_tmp);
	return (cmd);
}
