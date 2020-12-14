/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 08:43:39 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/14 13:39:38 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool			check_file(t_string line)
{
	int		count;

	count = 1;
	if (is_redirection(line[g_counter])){
		while (is_redirection(line[g_counter]))
		{
			if (count > 2)
			{
				g_char = line[g_counter];
				if (g_char == '>')
					g_err_msg = G_REDIRECT_ERR;
				else
					g_err_msg = L_REDIRECT_ERR;
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
