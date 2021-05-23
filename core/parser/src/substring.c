/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:10:44 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 13:02:26 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_string	substring(t_string string, int start, int end)
{
	t_string	sub;
	int			i;

	if (!string || end < start || start < 0)
		return (NULL);
	i = 0;
	sub = (t_string)malloc((end - start) + 2);
	while (start <= end)
		sub[i++] = string[start++];
	sub[i] = 0;
	return (sub);
}
