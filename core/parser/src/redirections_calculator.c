/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_calculator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:21:55 by ielbadao          #+#    #+#             */
/*   Updated: 2021/04/01 23:12:48 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static void		help_function(t_string command, int *count)
{
	skip_redirection(command);
	skip_spaces(command);
	if (command[g_counter] == '\'' || command[g_counter] == '"')
		g_char = command[g_counter++];
	skip_word(command);
	(*count)++;
}

int				redirections_calculator(t_string command)
{
	int		count;

	count = 0;
	g_counter = 0;
	while (command[g_counter])
	{
		g_char = 0;
		skip_spaces(command);
		if (is_redirection(command[g_counter]))
			help_function(command, &count);
		else
		{
			if (command[g_counter] == '\'' || command[g_counter] == '"')
				g_char = command[g_counter++];
			skip_word(command);
		}
		if (command[g_counter] && !is_redirection(command[g_counter]))
			g_counter++;
	}
	return (count);
}
