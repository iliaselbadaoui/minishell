/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:46:51 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/15 14:28:01 by ielbadao         ###   ########.fr       */
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
		g_err_msg = NO_FILE_NAME_ERR;
		return (false);
	}
	if (!string[g_counter])
	{
		if (g_char == '\'')
			g_err_msg = S_QUOTE_ERR;
		else
			g_err_msg = D_QUOTE_ERR;
		return (false);
	}
	else if(string[g_counter] == g_char)
	{
		g_counter++;
		return (true);
	}	
	return (true);
}
