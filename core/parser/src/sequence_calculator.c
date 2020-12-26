/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_calculator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:51:10 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/26 17:35:08 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int				sequence_calculator(t_string line, char delimiter)
{
	int		sequences;

	sequences = 0;
	while (line[g_counter])
	{
		if (line[g_counter] == '"' || line[g_counter] == '\'')
		{
			g_char = line[g_counter];
			g_counter++;
			while (line[g_counter] != g_char)
				g_counter++;
		}
		if (line[g_counter] == '\\')
			g_counter += 2;
		if (line[g_counter] == delimiter)
		{
			sequences++;
			if (!g_flag)
				sequences++;
			g_flag = 1;
		}
		g_counter++;
	}
	if (!g_flag)
		sequences++;
	g_flag = 0;
	g_counter = 0;
	return (sequences);
}
