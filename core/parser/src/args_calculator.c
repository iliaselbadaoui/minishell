/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:21:45 by ielbadao          #+#    #+#             */
/*   Updated: 2021/04/01 11:01:58 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int				args_calculator(t_string command)
{
	int		count;
	t_coord	coord;

	if (ft_strlen(command) == 1)
		return (1);
	count = 0;
	g_counter = 0;
	while (command[g_counter])
	{
		coord = get_next_arg(command);
		if (coord.end > coord.start)
			count++;
	}
	return (count);
}
