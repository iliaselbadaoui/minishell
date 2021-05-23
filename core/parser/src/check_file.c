/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 08:43:39 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 11:11:13 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool	check_file(t_string line)
{
	int		count;

	count = 1;
	if (is_redirection(line[g_container->counter]))
	{
		g_container->gchar = line[g_container->counter];
		while (is_redirection(line[g_container->counter]))
		{
			if (count > 2)
			{
				g_container->gchar = line[g_container->counter];
				return (false);
			}
			g_container->counter++;
			count++;
		}
		if (!check_file_name(line))
			return (false);
	}
	return (true);
}
