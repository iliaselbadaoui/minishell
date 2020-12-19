/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 08:43:39 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/19 08:46:33 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool			check_file(t_string line)
{
	int		count;

	count = 1;
	if (is_redirection(line[g_counter]))
	{
		g_char = line[g_counter];
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
		if (!check_file_name(line))
			return (false);
	}
	return (true);
}
