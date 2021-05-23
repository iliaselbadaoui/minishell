/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equals.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:37:52 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 13:03:00 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool	equals(t_string s1, t_string s2)
{
	t_bool	flag;

	flag = false;
	while (*s1 == *s2 && *s1 && *s2)
	{
		flag = true;
		s1++;
		s2++;
	}
	if (*s1 || *s2)
		flag = false;
	return (flag);
}
