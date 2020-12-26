/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:21:45 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/26 10:06:44 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static void		if_is_quote(t_string line)
{
	if (line[g_counter] == '\'' || line[g_counter] == '"')
		g_char = line[g_counter++];
}

int				args_calculator(t_string command)
{
	int		count;

	count = 0;
	g_counter = 0;
	while (command[g_counter])
	{
		skip_spaces(command);
		g_char = 0;
		if (is_redirection(command[g_counter]))
		{
			skip_redirection(command);
			skip_spaces(command);
			if_is_quote(command);
			skip_word(command);
		}
		else
		{
			if (command[g_counter] == '\'' || command[g_counter] == '"')
				g_char = command[g_counter++];
			skip_word(command);
			if (command[g_counter])
				count++;
		}
	}
	return (count);
}
