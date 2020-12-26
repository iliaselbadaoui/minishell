/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_calculator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:51:10 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/26 18:17:25 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static void		help(int *seq)
{
	if (!g_flag)
		(*seq)++;
	g_counter = 0;
	g_flag = 0;
}

int				sequence_calculator(t_string line, char delimiter)
{
	int		sequences;

	g_counter = sequences = 0;
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
			if (!g_flag++)
				sequences++;
		}
		g_counter++;
	}
	help(&sequences);
	return (sequences) ;
}
