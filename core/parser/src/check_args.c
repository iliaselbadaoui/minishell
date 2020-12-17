/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:01:13 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/17 13:47:36 by ielbadao         ###   ########.fr       */
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
