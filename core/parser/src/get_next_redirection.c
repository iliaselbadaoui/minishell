/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:36:37 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/28 02:30:49 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static char		get_redirection_type(t_string command)
{
	if (command[g_counter] == '>' && command[g_counter + 1] == '>')
		return ('a');
	else if (command[g_counter] == '>')
		return ('c');
	else
		return ('r');
}

static void		if_is_quote(t_string line)
{
	if (line[g_counter] == '\'' || line[g_counter] == '"')
		g_char = line[g_counter++];
}

t_coord			get_next_redirection(t_string line)
{
	t_coord		coord;

	while (line[g_counter])
	{
		g_char = 0;
		if (is_redirection(line[g_counter]))
		{
			coord.type = get_redirection_type(line);
			skip_redirection(line);
			skip_spaces(line);
			coord.start = g_counter;
			if_is_quote(line);
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
		g_counter++;
	}
	return ((t_coord){0, 0, 0});
}
