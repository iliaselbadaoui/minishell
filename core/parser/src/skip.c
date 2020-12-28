/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:56:59 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/28 02:07:34 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void			skip_word(t_string command)
{
	if (g_char > 0)
	{
		while (command[g_counter] != g_char)
			g_counter++;
		g_counter++;
	}
	else
		while (greate_question(command))
			g_counter++;
}

void			skip_spaces(t_string command)
{
	while (command[g_counter] == ' ')
		g_counter++;
}

void			skip_redirection(t_string command)
{
	if (command[g_counter] == '>' && command[g_counter + 1] == '>')
		g_counter += 2;
	else
		g_counter++;
}
