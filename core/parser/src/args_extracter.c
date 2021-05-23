/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_extracter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:09:31 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 12:42:11 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static void	extracter_helper(t_string *args, t_string command, int i)
{
	t_coord		coord;
	t_string	tmp;

	if (ft_strlen(command) == 1)
	{
		args[i] = ft_strdup(command);
		return ;
	}
	coord = get_next_arg(command);
	tmp = NULL;
	if (coord.end >= coord.start)
	{
		tmp = substring(command, coord.start, coord.end);
		args[i] = ft_strdup(trim(tmp));
		free(tmp);
	}
}

t_string	*args_extracter(t_string command)
{
	t_string	*args;
	int			count;
	int			i;

	g_container->counter = 0;
	count = args_calculator(command) + 1;
	g_container->counter = 0;
	args = (t_string *)malloc(sizeof(t_string) * count);
	g_container->counter = 0;
	i = 0;
	while (i < count - 1)
	{
		extracter_helper(args, command, i);
		i++;
	}
	args[i] = NULL;
	g_container->counter = 0;
	return (args);
}
