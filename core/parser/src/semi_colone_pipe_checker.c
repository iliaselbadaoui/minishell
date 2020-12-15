/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semi_colone_pipe_checker.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 10:29:06 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/15 11:12:22 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool			semi_colone_pipe_checker(t_string line)
{
	g_err_msg = NULL;
	if (line[0] == ';')
		g_err_msg = SC_SYN_ERR;
	else if (line[0] == '|')
		g_err_msg = PIPE_SYN_ERR;
	if (g_err_msg)
		return (false);
	if (line[g_counter] == '|')
	{
		g_counter++;
		while (line[g_counter] && line[g_counter] == ' ')
			g_counter++;
		if (!line[g_counter])
		{
			g_err_msg = PIPE_SYN_ERR;
			return (false);
		}
	}
	else
	{
		g_counter++;
		while (line[g_counter] && line[g_counter] == ' ')
			g_counter++;
	}
	return (true);
}
