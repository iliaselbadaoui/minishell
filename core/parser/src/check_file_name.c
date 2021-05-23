/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:53:53 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 12:05:16 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool	greate_question(t_string line)
{
	if (!is_redirection(line[g_container->counter])
		&& line[g_container->counter] && line[g_container->counter] != '|'
		&& line[g_container->counter] != ';'
		&& line[g_container->counter] != ' ')
		return (true);
	else
		return (false);
}

static t_bool	no_quote_file_name(t_string line)
{
	escape_spaces(line);
	if (line[g_container->counter] == ';'
		&& (!semi_colone_pipe_checker(line) || g_container->flag == 2))
	{
		g_container->error = NO_FILE_DIR;
		return (false);
	}
	else if (line[g_container->counter] == '|'
		&& (!semi_colone_pipe_checker(line) || g_container->flag == 2))
	{
		g_container->error = NO_FILE_DIR;
		return (false);
	}
	return (true);
}

t_bool	check_file_name(t_string line)
{
	while (line[g_container->counter] && line[g_container->counter] == ' ')
		g_container->counter++;
	if (!line[g_container->counter])
		return (false);
	if (!char_escape(line))
		return (false);
	if (line[g_container->counter] == '\"'
		|| line[g_container->counter] == '\'')
	{
		g_container->gchar = line[g_container->counter++];
		if (!is_quote(true, line))
			return (false);
		return (true);
	}
	if (!no_quote_file_name(line))
		return (false);
	return (true);
}
