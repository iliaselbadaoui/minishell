/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:36:37 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 11:22:24 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static char	get_redirection_type(t_string command)
{
	if (command[g_container->counter] == '>'
		&& command[g_container->counter + 1] == '>')
		return ('a');
	else if (command[g_container->counter] == '>')
		return ('c');
	else
		return ('r');
}

static void	if_is_quote(t_string line)
{
	if (line[g_container->counter] == '\''
		|| line[g_container->counter] == '"')
		g_container->gchar = line[g_container->counter++];
}

static void	help_function(t_string line, t_coord *coord)
{
	skip_redirection(line);
	skip_spaces(line);
	coord->start = g_container->counter;
	if_is_quote(line);
}

static void	helper(t_string line)
{
	if (line[g_container->counter]
		&& !is_redirection(line[g_container->counter]))
		g_container->counter++;
}

t_coord	get_next_redirection(t_string line)
{
	t_coord		coord;

	while (line[g_container->counter])
	{
		g_container->gchar = 0;
		skip_spaces(line);
		if (is_redirection(line[g_container->counter]))
		{
			coord.type = get_redirection_type(line);
			help_function(line, &coord);
			skip_word(line);
			coord.end = g_container->counter - 1;
			return (coord);
		}
		else
		{
			if (line[g_container->counter] == '\''
				|| line[g_container->counter] == '"')
				g_container->gchar = line[g_container->counter++];
			skip_word(line);
		}
		helper(line);
	}
	return ((t_coord){0, 0, 0});
}
