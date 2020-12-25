/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_delimiter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 11:10:52 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/24 14:32:15 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int				get_next_delimiter(t_string line, char delimiter)
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
			g_counter++;
			return (g_counter - 2);
		}
		g_counter++;
	}
	return (g_counter - 1);
}
