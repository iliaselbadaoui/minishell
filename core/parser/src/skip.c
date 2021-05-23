/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:56:59 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 11:51:46 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static void	help(t_string command)
{
	if (command[g_container->counter] == '\\'
		&& command[g_container->counter + 1] != '\''
		&& g_container->gchar != '\'')
		g_container->counter += 2;
	while (greate_question(command))
	{
		if (check_quote(command[g_container->counter]))
		{
			g_container->gchar = command[g_container->counter++];
			while (command[g_container->counter] != g_container->gchar)
				g_container->counter++;
		}
		g_container->counter++;
	}
}

void	skip_word(t_string command)
{
	if (g_container->gchar > 0)
	{
		while (command[g_container->counter] != g_container->gchar)
		{
			if (command[g_container->counter] == '\\'
				&& command[g_container->counter + 1] != '\''
				&& g_container->gchar != '\'')
			{
				g_container->counter += 2;
				continue ;
			}
			g_container->counter++;
		}
		g_container->counter++;
		help(command);
	}
	else
		help(command);
}

void	skip_spaces(t_string command)
{
	while (command[g_container->counter] == ' ')
		g_container->counter++;
}

void	skip_redirection(t_string command)
{
	if (command[g_container->counter] == '>'
		&& command[g_container->counter + 1] == '>')
		g_container->counter += 2;
	else
		g_container->counter++;
}
