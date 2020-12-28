/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:46:51 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/27 23:43:34 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool			is_quote(t_bool is_file, t_string string)
{
	static int		counter;

	while (string[g_counter] != g_char && string[g_counter])
	{
		counter++;
		g_counter++;
	}
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

t_bool			check_quote(char c)
{
	if (c == '"' || c == '\'')
		return (true);
	return (false);
}
