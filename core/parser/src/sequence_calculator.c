/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_calculator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:51:10 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/26 12:57:40 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int				sequence_calculator(t_string line, char delimiter)
{
	int		sequences;

	sequences = 0;
	g_counter = 0;
	while (line[g_counter])
	{
		skip_spaces(line);
		if (line[g_counter] == '"' || line[g_counter] == '\'')
		{
			g_char = line[g_counter++];
			while (line[++g_counter - 1] != g_char)
			{
				g_counter++;
			}
			sequences++;
		}
		else
		{
			while (line[g_counter] != delimiter && line[g_counter] != '"' &&
			line[g_counter] != '\"' && line[g_counter])
				g_counter++;
			sequences++;
		}
	}
	g_counter = 0;
	return (sequences);
}
