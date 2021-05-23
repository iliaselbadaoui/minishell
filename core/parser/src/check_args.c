/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:01:13 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 13:03:38 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool	check_args(t_string line)
{
	t_bool		bol;

	while (line[g_container->counter])
	{
		bol = char_escape(line);
		if (bol == true)
			continue ;
		else if (bol == false)
			return (false);
		if (line[g_container->counter] == '\"'
			|| line[g_container->counter] == '\'')
		{
			g_container->gchar = line[g_container->counter++];
			if (!is_quote(false, line))
				return (false);
			continue ;
		}
		else if (line[g_container->counter] == ';'
			|| line[g_container->counter] == '|'
			|| is_redirection(line[g_container->counter]))
			return (true);
		g_container->counter++;
	}
	return (true);
}
