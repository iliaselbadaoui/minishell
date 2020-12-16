/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:23:30 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/16 13:28:34 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void			escape_spaces(t_string line)
{
	while (line[g_counter] == ' ')
		g_counter++;
	if (!greate_question(line) && g_flag != 1)
		g_flag = 2;
}
