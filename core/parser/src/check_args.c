/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:01:13 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/12 18:40:21 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool			check_args(t_string line)
{
	while (*line)
	{
		if (*line == '\"' || *line == '\'')
		{
			g_char = *line++;
			while (*line != g_char && *line)
				line++;
			if (!*line)
				return (false);
			else if(*line == g_char)
				line++;
		}
		else if (*line == ';' || *line == '|' || is_redirection(*line))
			return (true);
		line++;
	}
	return (true);
}
