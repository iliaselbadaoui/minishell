/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:46:51 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/13 08:43:07 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool			is_quote(t_string string)
{
	while (string[g_counter] != g_char && string[g_counter])
		g_counter++;
	if (!string[g_counter])
		return (false);
	else if(string[g_counter] == g_char)
	{
		g_counter++;
		return (true);
	}
	else
		return (true);
}
