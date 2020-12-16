/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semi_colone_pipe_checker.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 10:29:06 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/16 13:10:17 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool			semi_colone_pipe_checker(t_string line)
{
	if (line[0] == ';' || line[0] == '|')
		return (false);
	if (line[g_counter] == '|')
	{
		g_counter++;
		while (line[g_counter] && line[g_counter] == ' ')
			g_counter++;
		if (!line[g_counter])
			return (false);
	}
	else
	{
		g_counter++;
		while (line[g_counter] && line[g_counter] == ' ')
			g_counter++;
	}
	return (true);
}
