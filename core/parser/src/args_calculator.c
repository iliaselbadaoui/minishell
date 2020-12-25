/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:21:45 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/25 16:57:29 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int				args_calculator(t_string command)
{
	int		count;

	count = 0;
	while (command[g_counter])
	{
		skip_spaces(command);
		g_char = 0;
		if (is_redirection(command[g_counter]))
		{
			g_counter++;
			skip_spaces(command);
			if (command[g_counter] == '\'' || command[g_counter] == '"')
				g_char = command[g_counter++];
			skip_word(command);
		}
		else
		{
			if (command[g_counter] == '\'' || command[g_counter] == '"')
				g_char = command[g_counter++];
			skip_word(command);
			count++;
		}
	}
	return (count);
}
