/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:27:40 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 00:58:24 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../out.h"

void	out(t_string str)
{
	while (*str)
	{
		if (*str)
		{
			write(1, str, 1);
			str++;
		}
		if (*str)
		{
			write(1, str, 1);
			str++;
		}
		if (*str)
		{
			write(1, str, 1);
			str++;
		}
		if (*str)
		{
			write(1, str, 1);
			str++;
		}
	}
}
