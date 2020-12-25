/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:30:45 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/24 14:24:45 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_string		*spliter_grid(t_string line, char delimiter)
{
	int			sequences;
	int			start;
	int			end;
	int			i;
	t_string	*res;

	sequences = sequence_calculator(line, delimiter) + 1;
	res = (t_string *)malloc(sizeof(t_string) * sequences);
	res[sequences - 1] = NULL;
	start = 0;
	i = 0;
	while (i < sequences - 1)
	{
		end = get_next_delimiter(line, delimiter);
		res[i] = substring(line, start, end);
		start = end + 2;
		i++;
	}
	return (res);
}
