/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:46:51 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 11:24:08 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static t_bool	is_quote_help(t_bool is_file, t_string string, int counter)
{
	if (is_file && !counter)
	{
		g_container->error = NO_FILE_DIR;
		return (false);
	}
	if (!string[g_container->counter])
		return (false);
	else if (string[g_container->counter] == g_container->gchar)
	{
		g_container->counter++;
		return (true);
	}
	return (false);
}

t_bool	is_quote(t_bool is_file, t_string string)
{
	static int		counter;

	while (string[g_container->counter] != g_container->gchar
		&& string[g_container->counter])
	{
		if (string[g_container->counter] == '\\'
			&& string[g_container->counter + 1] == g_container->gchar
			&& g_container->gchar == '\'')
		{
			g_container->counter += 2;
			return (true);
		}
		else if (string[g_container->counter] == '\\'
			&& string[g_container->counter + 1] == g_container->gchar)
		{
			g_container->counter += 2;
			continue ;
		}
		counter++;
		g_container->counter++;
	}
	return (is_quote_help(is_file, string, counter));
}

t_bool	check_quote(char c)
{
	if (c == '"' || c == '\'')
		return (true);
	return (false);
}
