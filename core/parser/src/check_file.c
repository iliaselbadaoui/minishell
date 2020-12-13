/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 08:43:39 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/13 14:43:21 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool		check_file(t_string line)
{
	// int		flag;
	int		count;

	count = 0;
	while (line[g_counter])
	{
		while (is_redirection(line[g_counter]))
		{
			if (count > 2)
			{
				g_char = line[g_counter];
				return (false);
			}
			g_counter++;
			count++;
		}
		g_counter++;
	}
	return (true);
}
