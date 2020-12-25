/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_extracter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:09:31 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/25 18:25:17 by ielbadao         ###   ########.fr       */
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
	args = (t_string *)malloc(sizeof(t_string) * g_counter);
	args[count - 1] = NULL;
	i = 0;
	while (i < count)
	{
		coord = get_next_arg(command);
		printf("START : %d\nEND : %d\n", coord.start, coord.end);
		args[i] = substring(command, coord.start, coord.end);
		i++;
	}
	
	return (args);
}
