/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_delimiter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 11:10:52 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 01:29:11 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int	get_next_delimiter(t_string line, char delimiter)
{
	while (line[g_container->spliter_counter])
	{
		if (check_quote(line[g_container->spliter_counter]))
		{
			g_container->spliter_char = line[g_container->spliter_counter++];
			while (line[g_container->spliter_counter]
				!= g_container->spliter_char)
				g_container->spliter_counter++;
			g_container->spliter_counter++;
		}
		if (line[g_container->spliter_counter] == '\\')
			g_container->spliter_counter += 2;
		if (line[g_container->spliter_counter] == delimiter)
		{
			g_container->spliter_counter++;
			return (g_container->spliter_counter - 2);
		}
		g_container->spliter_counter++;
	}
	return (g_container->spliter_counter - 1);
}
