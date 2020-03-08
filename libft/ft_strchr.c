/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 08:32:21 by ielbadao          #+#    #+#             */
/*   Updated: 2020/03/07 18:33:07 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char *res;

	res = NULL;
	while (*s)
	{
		if (*s == c)
		{
			res = (char *)s;
			break ;
		}
		s++;
	}
	if (*s == c)
		res = (char *)s;
	return (res);
}
