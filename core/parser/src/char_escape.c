/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_escape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 09:04:11 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/14 13:34:31 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"


t_bool		char_escape(t_string line)
{
	if (line[g_counter] == '\\' && line[g_counter + 1] != '\0')
	{
		g_counter += 2;
		return (true);
	}
	else if(line[g_counter] == '\\' && line[g_counter + 1] == '\0')
	{
		g_char = line[g_counter];
		g_err_msg = CHAR_ESC_ERR;
		return (false);
	}
	return (2);
}
