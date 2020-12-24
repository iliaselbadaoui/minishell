/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:30:45 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/24 11:41:36 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_string		*spliter_grid(t_string line, char delimiter)
{
	int			sequences;
	int			start;
	int			end;
	t_string	*res;

	sequences = sequence_calculator(line, delimiter) + 1;
	res = (t_string *)malloc(sizeof(t_string) * sequences);
	res[sequences - 1] = NULL;
	start = 0;
	sequences = 0;
	while (res[sequences])
	{
		end = get_next_delimiter(line, delimiter);
		res[sequences] = substring(line, start, end);
		start = end + 2;
		sequences++;
	}
	return (res);
}
