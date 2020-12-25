/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_extracter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:20:44 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/25 22:16:27 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_redirect		*redirections_extracter(t_string command)
{
	t_redirect	*redirections;
	int			count;
	int			i;
	t_coord		coord;
	t_redirect	red;
	
	count = redirections_calculator(command) + 1;
	g_counter = 0;
	redirections = malloc(sizeof(t_redirect) * count);
	i = 0;
	while (i < count - 1)
	{
		coord = get_next_arg(command);
		red.type = coord.type;
		if (coord.end)
			red.file_name = substring(command, coord.start, coord.end);
		i++;
	}
	return (redirections);
}
