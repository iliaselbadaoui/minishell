/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:22:11 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/28 02:13:45 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_coord			get_next_arg(t_string line)
{
	t_coord		coord;

	while (line[g_counter])
	{
		g_char = 0;
		if (is_redirection(line[g_counter]))
		{
			skip_redirection(line);
			skip_spaces(line);
			if (line[g_counter] == '\'' || line[g_counter] == '"')
				g_char = line[g_counter++];
			skip_word(line);
		}
		else
		{
			coord.start = g_counter;
			if (line[g_counter] == '\'' || line[g_counter] == '"')
				g_char = line[g_counter++];
			skip_word(line);
			coord.end = g_counter - 1;
			return (coord);
		}
		g_counter++;
	}
	return ((t_coord){0, 0, 0});
}
