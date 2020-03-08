/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:32:22 by ielbadao          #+#    #+#             */
/*   Updated: 2020/03/08 11:25:05 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		line_parser(t_string line)
{
	if (equals(line, "exit"))
		return (EXIT);
	return (CONTINUE);
}
