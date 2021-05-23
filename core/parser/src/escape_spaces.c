/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:23:30 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 11:25:38 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	escape_spaces(t_string line)
{
	while (line[g_container->counter] == ' ')
		g_container->counter++;
	if (!greate_question(line) && g_container->flag != 1)
		g_container->flag = 2;
}
