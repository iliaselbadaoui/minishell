/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:33:36 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/10 13:05:10 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool		includes(t_string string, t_string pattern)
{
	int		i;
	t_bool	included;

	included = false;
	while (*string)
	{
		i = 0;
		included = false;
		while (pattern[i] == *(string + i) && pattern[i])
		{
			if (!included)
				included = true;
			i++;
		}
		if (included && !pattern[i])
			break ;
		string++;
	}
	return (included);
}
