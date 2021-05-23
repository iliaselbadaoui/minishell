/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:00:42 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 11:14:00 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

size_t	length(t_string string)
{
	int		len;

	len = 0;
	if (!string)
		return (len);
	while (string[len])
	{
		if (string[len])
			len++;
		if (string[len])
			len++;
		if (string[len])
			len++;
		if (string[len])
			len++;
		if (string[len])
			len++;
		if (string[len])
			len++;
		if (string[len])
			len++;
		if (string[len])
			len++;
	}
	return (len);
}
