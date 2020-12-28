/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_extracter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:20:44 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/28 02:32:25 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static t_redirect	init_redirection(char type, t_string filename)
{
	return ((t_redirect){type, -1, filename});
}

t_redirect			*redirections_extracter(t_string command)
{
	t_redirect	*redirections;
	int			count;
	int			i;
	t_coord		coord;
	t_string	filename;

	g_counter = 0;
	count = redirections_calculator(command) + 1;
	g_counter = 0;
	redirections = malloc(sizeof(t_redirect) * count);
	i = 0;
	while (i < count - 1)
	{
		coord = get_next_redirection(command);
		if (coord.end)
			filename = substring(command, coord.start, coord.end);
		redirections[i] = init_redirection(coord.type, filename);
		i++;
	}
	redirections[i] = (t_redirect){0, -1, NULL};
	g_counter = 0;
	return (redirections);
}
