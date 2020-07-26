/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zeros_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 19:45:32 by ielbadao          #+#    #+#             */
/*   Updated: 2019/12/06 11:43:15 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_zeros_spaces(int value, int length)
{
	int size;

	size = value - length;
	if (size >= 0)
	{
		return (size);
	}
	else
	{
		return (0);
	}
}

int		ft_printable_length(int value, int length)
{
	if (value < length && value >= 0)
	{
		return (value);
	}
	else
	{
		return (length);
	}
}
