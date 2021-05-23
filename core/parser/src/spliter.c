/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:30:45 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 13:02:48 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_string	*spliter(t_string line, char delimiter)
{
	int			sequences;
	int			start;
	int			end;
	int			i;
	t_string	*res;

	g_container->spliter_counter = 0;
	g_container->spliter_char = 0;
	sequences = sequence_calculator(line, delimiter) + 1;
	res = (t_string *)malloc(sizeof(t_string) * sequences);
	i = 0;
	while (i < sequences - 1)
	{
		start = g_container->spliter_counter;
		end = get_next_delimiter(line, delimiter);
		res[i] = substring(line, start, end);
		i++;
	}
	res[i] = NULL;
	g_container->spliter_counter = 0;
	g_container->spliter_char = 0;
	return (res);
}
