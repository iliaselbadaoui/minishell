/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:53:53 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/14 13:40:17 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"


static void		no_quote_file_name(t_string line)
{
	while (!is_redirection(line[g_counter]) && line[g_counter] && 
		line[g_counter] != '|' && line[g_counter] != ';' && 
		line[g_counter] != ' ' && line[g_counter])
			g_counter++;
}

t_bool			check_file_name(t_string line)
{
	t_bool			bol;

	while (line[g_counter] && line[g_counter] == ' ')
		g_counter++;
	if(!line[g_counter])
		return (false);
	else
	{
		while (line[g_counter] && line[g_counter] != ' ')
			g_counter++;
		return (true);
	}
	if((bol = char_escape(line)) == false)
		return (false);
	if (line[g_counter] == '\"' || line[g_counter] == '\'')
	{
		g_char = line[g_counter++];
		if (!is_quote(line))
			return (false);
	}
	else
		no_quote_file_name(line);
	return (true);
}
