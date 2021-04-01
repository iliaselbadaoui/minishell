/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:22:11 by ielbadao          #+#    #+#             */
/*   Updated: 2021/04/01 10:03:28 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static void		help_function(t_string line)
{
	skip_redirection(line);
	skip_spaces(line);
	if (line[g_counter] == '\'' || line[g_counter] == '"')
		g_char = line[g_counter++];
	skip_word(line);
}

t_coord			get_next_arg(t_string line)
{
	t_coord		coord;

	while (line[g_counter])
	{
		g_char = 0;
		skip_spaces(line);
		if (is_redirection(line[g_counter]))
			help_function(line);
		else
		{
			coord.start = g_counter;
			if (line[g_counter] == '\'' || line[g_counter] == '"')
				g_char = line[g_counter++];
			else if (line[g_counter - 1] == ' ')
				coord.start = g_counter - 1;
			skip_word(line);
			coord.end = g_counter - 1;
			return (coord);
		}
		if (line[g_counter])
			g_counter++;
	}
	return ((t_coord){0, 0, 0});
}
