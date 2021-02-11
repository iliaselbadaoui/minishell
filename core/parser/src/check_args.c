/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:01:13 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/11 18:57:32 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool			check_args(t_string line)
{
	t_bool		bol;

	while (line[g_counter])
	{
		bol = char_escape(line);
		if (bol == true)
			continue ;
		else if (bol == false)
			return (false);
		if (line[g_counter] == '\"' || line[g_counter] == '\'')
		{
			g_char = line[g_counter++];
			if (!is_quote(false, line))
				return (false);
			continue ;
		}
		else if (line[g_counter] == ';' || line[g_counter] == '|' ||
		is_redirection(line[g_counter]))
			return (true);
		g_counter++;
	}
	return (true);
}
