/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_escape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 09:04:11 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 01:27:04 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool	char_escape(t_string line)
{
	if (line[g_container->counter] == '\\')
	{
		g_container->flag = 1;
		g_container->counter += 2;
		return (true);
	}
	else if (line[g_container->counter] == '\\'
		&& line[g_container->counter + 1] == '\0')
	{
		g_container->gchar = line[g_container->counter];
		return (false);
	}
	return (2);
}
