/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:30:45 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/25 19:22:07 by ielbadao         ###   ########.fr       */
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
	start = 0;
	i = 0;
	while (i < sequences)
	{
		end = get_next_delimiter(line, delimiter);
		res[i] = substring(line, start, end);
		start = end + 2;
		i++;
	}
	res[i] = NULL;
	return (res);
}
