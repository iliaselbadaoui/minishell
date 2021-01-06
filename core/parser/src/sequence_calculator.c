/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence_calculator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:51:10 by ielbadao          #+#    #+#             */
/*   Updated: 2021/01/06 10:33:56 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static void	help(t_string line, int *count, int *flag)
{
	if (check_quote(line[g_spliter_counter]))
	{
		if (!(*flag))
		{
			(*count)++;
			*flag = 1;
		}
		g_spliter_char = line[g_spliter_counter++];
		while (line[g_spliter_counter] != g_spliter_char)
			g_spliter_counter++;
		g_spliter_counter++;
	}
}

static void	help2(t_string line, char delimiter, int *count, int *flag)
{
	if (line[g_spliter_counter] != delimiter)
	{
		if (!(*flag))
		{
			(*count)++;
			*flag = 1;
		}
		while (!check_quote(line[g_spliter_counter]) &&
		line[g_spliter_counter] != delimiter && line[g_spliter_counter])
		{
			if (line[g_spliter_counter] == '\\')
				g_spliter_counter += 2;
			else
				g_spliter_counter++;
		}
	}
}

int				sequence_calculator(t_string line, char delimiter)
{
	int		count;
	int		flag;

	count = 0;
	flag = 0;
	g_spliter_counter = 0;
	g_spliter_char = 0;
	while (line[g_spliter_counter])
	{
		help(line, &count, &flag);
		help2(line, delimiter, &count, &flag);
		if (line[g_spliter_counter] == delimiter)
			flag = 0;
		g_spliter_counter++;
	}
	g_spliter_counter = 0;
	g_spliter_char = 0;
	return (count);
}
