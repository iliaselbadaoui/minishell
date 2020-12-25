/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:36:37 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/25 22:12:55 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static char		get_redirection_type(t_string command)
{
	if (command[g_counter] == '>')
		return ('c');
	else if (command[g_counter] == '>' && command[g_counter + 1] == '>')
		return ('a');
	else
		return ('r');
}

t_coord			get_next_redirection(t_string line)
{
	t_coord		coord;
	
	while (line[g_counter])
	{
		skip_spaces(line);
		g_char = 0;
		if (is_redirection(line[g_counter]))
		{
			coord.type = get_redirection_type(line);
			skip_redirection(line);
			skip_spaces(line);
			coord.start = g_counter;
			if (line[g_counter] == '\'' || line[g_counter] == '"')
				g_char = line[g_counter++];
			skip_word(line);
			coord.end = g_counter - 1;
			return (coord);
		}
		else
		{
			if (line[g_counter] == '\'' || line[g_counter] == '"')
				g_char = line[g_counter++];
			skip_word(line);
		}
	}
	return ((t_coord){0,0});
}
