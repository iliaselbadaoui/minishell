/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_calculator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:21:55 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/28 02:16:53 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int				redirections_calculator(t_string command)
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
			if (command[g_counter] == '\'' || command[g_counter] == '"')
				g_char = command[g_counter++];
			skip_word(command);
			count++;
		}
		else
		{
			if (command[g_counter] == '\'' || command[g_counter] == '"')
				g_char = command[g_counter++];
			skip_word(command);
		}
		g_counter++;
	}
	return (count);
}
