/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:01:13 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/13 13:08:41 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool			check_args(t_string line)
{
	while (line[g_counter])
	{
		if (line[g_counter] == '\\' && line[g_counter + 1] != '\0')
		{
			g_counter += 2;
			continue ;
		}
		else if(line[g_counter] == '\\' && line[g_counter + 1] == '\0')
		{
			g_char = line[g_counter];
			return (false);
		}
		if (line[g_counter] == '\"' || line[g_counter] == '\'')
		{
			g_char = line[g_counter++];
			if (!is_quote(line))
				return (false);
			continue ;
		}
		else if (line[g_counter] == ';' || line[g_counter] == '|' || is_redirection(line[g_counter]))
			return (true);
		g_counter++;
	}
	return (true);
}
