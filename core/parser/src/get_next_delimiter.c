/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_delimiter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 11:10:52 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/28 10:21:08 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int				get_next_delimiter(t_string line, char delimiter)
{
	while (line[g_spliter_counter])
	{
		if (check_quote(line[g_spliter_counter]))
		{
			g_spliter_char = line[g_spliter_counter++];
			while (line[g_spliter_counter] != g_spliter_char)
				g_spliter_counter++;
			g_spliter_counter++;
		}
		if (line[g_spliter_counter] == '\\')
			g_spliter_counter += 2;
		if (line[g_spliter_counter] == delimiter)
		{
			g_spliter_counter++;
			return (g_spliter_counter - 2);
		}
		g_spliter_counter++;
	}
	return (g_spliter_counter - 1);
}
