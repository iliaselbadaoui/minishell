/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:56:59 by ielbadao          #+#    #+#             */
/*   Updated: 2021/04/01 23:04:41 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static void		help(t_string command)
{
	if (command[g_counter] == '\\' && command[g_counter + 1] != '\'' &&
	g_char != '\'')
		g_counter += 2;
	while (greate_question(command))
	{
		if (check_quote(command[g_counter]))
		{
			g_char = command[g_counter++];
			while (command[g_counter] != g_char)
				g_counter++;
		}
		g_counter++;
	}
}

void			skip_word(t_string command)
{
	if (g_char > 0)
	{
		while (command[g_counter] != g_char)
		{
			if (command[g_counter] == '\\' && command[g_counter + 1] != '\'' &&
			g_char != '\'')
			{
				g_counter += 2;
				continue ;
			}
			g_counter++;
		}
		g_counter++;
		help(command);
	}
	else
		help(command);
}

void			skip_spaces(t_string command)
{
	while (command[g_counter] == ' ')
		g_counter++;
}

void			skip_redirection(t_string command)
{
	if (command[g_counter] == '>' && command[g_counter + 1] == '>')
		g_counter += 2;
	else
		g_counter++;
}
