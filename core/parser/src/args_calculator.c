/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:21:45 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/28 12:32:41 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static void		if_is_quote(t_string line)
{
	if (check_quote(line[g_counter]))
		g_char = line[g_counter++];
}

int				args_calculator(t_string command)
{
	int		count;

	count = 0;
	g_counter = 0;
	while (command[g_counter])
	{
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
			if (check_quote(command[g_counter]))
				g_char = command[g_counter++];
			skip_word(command);
			count++;
		}
		g_counter++;
	}
	return (count);
}
