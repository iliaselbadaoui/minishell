/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:53:53 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/16 11:14:43 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"


t_bool			greate_question(t_string line)
{
	if (!is_redirection(line[g_counter]) && line[g_counter] && 
		line[g_counter] != '|' && line[g_counter] != ';' && 
		line[g_counter] != ' ')
		return (true);
	else
		return (false);	
}

static t_bool	no_quote_file_name(t_string line)
{	
	escape_spaces(line);
	if (!char_escape(line))
		return (false);
	else
		return (true);
	if (line[g_counter] == ';' && (!semi_colone_pipe_checker(line) || 
	g_flag))
		return (false);
	else if (line[g_counter] == '|' && (!semi_colone_pipe_checker(line) ||
	g_flag))
		return (false);
	return (true);
}

t_bool			check_file_name(t_string line)
{
	while (line[g_counter] && line[g_counter] == ' ')
		g_counter++;
	if(!line[g_counter])
		return (false);
	if(!char_escape(line))
		return (false);
	if (line[g_counter] == '\"' || line[g_counter] == '\'')
	{
		g_char = line[g_counter++];
		if (!is_quote(true, line))
			return (false);
	}
	return (no_quote_file_name(line));
}
