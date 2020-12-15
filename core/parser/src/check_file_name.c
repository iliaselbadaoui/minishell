/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:53:53 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/15 11:02:13 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"


static t_bool	no_quote_file_name(t_string line)
{
	while (!is_redirection(line[g_counter]) && line[g_counter] && 
		line[g_counter] != '|' && line[g_counter] != ';' && 
		line[g_counter] != ' ')
			g_counter++;
	if (line[g_counter - 1] == '/')
	{
		g_err_msg  = DIR_NAME_ERR;
		return (false);
	}
	else if (line[g_counter] == ';')
	{
		g_counter++;
		g_err_msg  = SC_SYN_ERR;
		return (false);
	}
	else if (line[g_counter] == '|')
	{
		g_counter++;
		g_err_msg  = PIPE_SYN_ERR;
		return (false);
	}
	return (true);
}

t_bool			check_file_name(t_string line)
{
	while (line[g_counter] && line[g_counter] == ' ')
		g_counter++;
	if(!line[g_counter])
	{
		g_err_msg = NO_FILE_NAME_ERR;
		return (false);
	}
	if(!char_escape(line))
		return (false);
	if (line[g_counter] == '\"' || line[g_counter] == '\'')
	{
		g_char = line[g_counter++];
		if (!is_quote(line))
			return (false);
	}
	return (no_quote_file_name(line));
}
