/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:46:51 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/17 13:50:50 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool			is_quote(t_bool is_file, t_string string)
{
	static int		counter;

	while (string[g_counter] != g_char && string[g_counter])
	{
		counter++;
		g_counter++;
	}
	if (is_file && !counter)
		return (false);
	if (!string[g_counter])
		return (false);
	else if (string[g_counter] == g_char)
	{
		g_counter++;
		return (true);
	}
	return (true);
}
