/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:30:45 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/23 16:42:36 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_string			spliter_grid(t_string line, char delimiter)
{
	int			sequences;
	t_string	*res;

	sequences = sequence_calculator(line, delimiter);
	res = (t_string *)malloc(sizeof(t_string) * sequences);
}
