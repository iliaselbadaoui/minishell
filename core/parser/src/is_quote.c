/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:46:51 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/19 10:56:00 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static t_bool	is_quote_help(t_bool is_file, t_string string, int counter)
{
	if (is_file && !counter)
	{
		g_error = NO_FILE_DIR;
		return (false);
	}
	if (!string[g_counter])
		return (false);
	else if (string[g_counter] == g_char)
	{
		g_counter++;
		return (true);
	}
	return (false);
}

t_bool			is_quote(t_bool is_file, t_string string)
{
	static int		counter;

	while (string[g_counter] != g_char && string[g_counter])
	{
		if (string[g_counter] == '\\' && string[g_counter + 1] == g_char &&
		g_char == '\'')
		{
			g_counter += 2;
			return (true);
		}
		else if (string[g_counter] == '\\' && string[g_counter + 1] == g_char)
		{
			g_counter += 2;
			continue;
		}
		counter++;
		g_counter++;
	}
	return (is_quote_help(is_file, string, counter));
}

t_bool			check_quote(char c)
{
	if (c == '"' || c == '\'')
		return (true);
	return (false);
}
