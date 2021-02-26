/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_extracter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:09:31 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/26 07:13:53 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static void		extracter_helper(t_string *args, t_string command, int *first, int i)
{
	t_coord		coord;
	t_string	tmp;

	coord = get_next_arg(command);
	tmp = NULL;
	if (coord.end >= coord.start)
	{
		tmp = substring(command, coord.start, coord.end);
		if (!(*first) && !is_option(trim(tmp)) && i != 0)
		{
			args[i] = ft_strdup(trim(tmp));
			*first = 1;
			free(tmp);
		}
		else
		{
			args[i] = ft_strdup(tmp);
			free(tmp);
			if (!(tmp = args[i]) && is_option(trim(args[i])))
			{
				args[i] = ft_strdup(trim(args[i]));
				free(tmp);
			}
		}
	}
}

t_string		*args_extracter(t_string command)
{
	t_string	*args;
	int			count;
	int			i;
	int			first;

	g_counter = 0;
	first = 0;
	count = args_calculator(command) + 1;
	g_counter = 0;
	args = (t_string *)malloc(sizeof(t_string) * count);
	i = 0;
	while (i < count - 1)
	{
		extracter_helper(args, command, &first, i);
		i++;
	}
	args[i] = NULL;
	g_counter = 0;
	return (args);
}
