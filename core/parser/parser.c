/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 15:29:09 by ielbadao          #+#    #+#             */
/*   Updated: 2020/07/02 11:06:11 by ielbadao         ###   ########.fr       */
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
			add_part(&cmd, sequencer(*commands));
			commands++;
		}
		free_double_char_arr(commands_tmp);
		pipe++;
	}
	free_double_char_arr(pipe_tmp);
	return (cmd);
}
