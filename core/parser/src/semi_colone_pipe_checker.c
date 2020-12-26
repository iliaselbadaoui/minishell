/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semi_colone_pipe_checker.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 10:29:06 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/26 09:48:17 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static t_bool	check_before_semi_colone(t_string line)
{
	int		tmp_counter;

	tmp_counter = g_counter - 1;
	while (line[tmp_counter] == ' ')
		tmp_counter--;
	if (line[tmp_counter] == ';' || line[tmp_counter] == '|')
		return (false);
	return (true);
}

t_bool			semi_colone_pipe_checker(t_string line)
{
	if (line[0] == ';' || line[0] == '|')
		return (false);
	if (line[g_counter] == '|')
	{
		g_counter++;
		while (line[g_counter] && line[g_counter] == ' ')
			g_counter++;
		if (!line[g_counter] || line[g_counter] == '|')
			return (false);
	}
	else if (line[g_counter] == ';')
	{
		if (!check_before_semi_colone(line))
			return (false);
		g_counter++;
		while (line[g_counter] && line[g_counter] == ' ')
			g_counter++;
	}
	return (true);
}
