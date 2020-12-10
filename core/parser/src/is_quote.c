/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:46:51 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/10 13:23:50 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool			is_quote(t_string string)
{
	if (!string || !length(string))
		return (false);
	if (string[0] == 34 && string[length(string) - 1] == 34)
		return (true);
	else if (string[0] == 39 && string[length(string) - 1] == 39)
		return (true);
	else
		return (false);
}
