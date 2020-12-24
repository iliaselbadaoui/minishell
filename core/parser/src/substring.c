/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:10:44 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/24 10:49:57 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_string		substring(t_string string, int start, int end)
{
	int			len;
	int			i;
	t_string	res;

	i = 0;
	len = end - start + 2;
	res = (t_string)malloc(len);
	while (start <= end)
	{
		res[i] = string[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
