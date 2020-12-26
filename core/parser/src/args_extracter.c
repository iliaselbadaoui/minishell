/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_extracter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:09:31 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/26 09:41:10 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_string		*args_extracter(t_string command)
{
	t_string	*args;
	int			count;
	int			i;
	t_coord		coord;

	count = args_calculator(command) + 1;
	g_counter = 0;
	args = (t_string *)malloc(sizeof(t_string) * count);
	i = 0;
	while (i < count - 1)
	{
		coord = get_next_arg(command);
		if (coord.end)
			args[i] = substring(command, coord.start, coord.end);
		i++;
	}
	args[i] = NULL;
	return (args);
}
