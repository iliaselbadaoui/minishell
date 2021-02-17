/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_extracter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:09:31 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/17 09:17:25 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_string		*args_extracter(t_string command)
{
	t_string	*args;
	t_string	tmp;
	int			count;
	int			i;
	t_coord		coord;

	g_counter = 0;
	count = args_calculator(command) + 1;
	g_counter = 0;
	args = (t_string *)malloc(sizeof(t_string) * count);
	i = 0;
	while (i < count - 1)
	{
		coord = get_next_arg(command);
		if (i == 1 && coord.end >= coord.start)
		{
			tmp = substring(command, coord.start, coord.end);
			args[i] = ft_strdup(trim(tmp));
			free(tmp);
		}
		else if (coord.end >= coord.start)
			args[i] = substring(command, coord.start, coord.end);
		i++;
	}
	args[i] = NULL;
	g_counter = 0;
	return (args);
}
