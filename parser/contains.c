/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:57:54 by ielbadao          #+#    #+#             */
/*   Updated: 2020/03/08 10:39:06 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			contains(t_string container, t_string content)
{
	int iter;

	while (*container)
	{
		if (*container == *content)
		{
			iter = 1;
			container++;
			while (content[iter])
			{
				if (content[iter] != *container)
				{
					container -= iter;
					iter = 0;
					break ;
				}
				iter++;
				container++;
			}
			if (iter)
				return (1);
		}
		container++;
	}
	return (0);
}
