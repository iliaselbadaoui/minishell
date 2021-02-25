/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_extracter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:09:31 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/25 18:51:35 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static void		extracter_helper(t_string *args, t_string command, int i)
{
	t_coord		coord;
	t_string	tmp;

	coord = get_next_arg(command);
	if (i == 1 && coord.end >= coord.start)
	{
		tmp = substring(command, coord.start, coord.end);
		args[i] = ft_strdup(trim(tmp));
		free(tmp);
	}
	else if (coord.end >= coord.start)
	{
		args[i] = substring(command, coord.start, coord.end);
		if (is_option(trim(args[i])) == true)
		{
			tmp = args[i];
			args[i] = ft_strdup(trim(args[i]));
			free(tmp);
		}
	}
}

t_string		*args_extracter(t_string command)
{
	t_string	*args;
	int			count;
	int			i;

	g_counter = 0;
	count = args_calculator(command) + 1;
	g_counter = 0;
	args = (t_string *)malloc(sizeof(t_string) * count);
	i = 0;
	while (i < count - 1)
	{
		extracter_helper(args, command, i);
		i++;
	}
	args[i] = NULL;
	g_counter = 0;
	return (args);
}
