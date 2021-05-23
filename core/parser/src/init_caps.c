/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_caps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:52:12 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 11:52:58 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int	init_caps(void)
{
	char	*type;
	int		res;

	type = getenv("TERM");
	if (!type)
	{
		out("TERM must be set (see 'env').\n");
		return (-1);
	}
	res = tgetent(NULL, type);
	if (res == -1)
	{
		out("Could not access to the termcap database..\n");
		return (-1);
	}
	else if (res == 0)
	{
		out("Terminal type '");
		out(type);
		out("' is not defined in termcap database.\n");
		return (-1);
	}
	return (0);
}
