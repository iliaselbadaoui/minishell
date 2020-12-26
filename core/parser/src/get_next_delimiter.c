/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_delimiter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 11:10:52 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/26 17:12:35 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int				get_next_delimiter(t_string line, char delimiter)
{
	while (line[g_counter])
	{
		if (line[g_counter] == '"' || line[g_counter] == '\'')
		{
			g_char = line[g_counter++];
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
