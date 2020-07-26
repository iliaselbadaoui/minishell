/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 10:43:16 by ielbadao          #+#    #+#             */
/*   Updated: 2019/12/06 15:05:54 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	positive_zero(t_format_container c)
{
	if (c.type.i < 0)
		ft_putchar_fd('-', 1);
	if (*(c.conv) == 'i' || *(c.conv) == 'd')
	{
		ft_char_times('0', ft_zeros_spaces(c.values.zero_value,
		ft_nb_length(c.type.i)));
		ft_putnbr_fd(ft_abs(c.type.i), 1);
	}
	else if (*(c.conv) == 'u')
	{
		ft_char_times('0', ft_zeros_spaces(c.values.zero_value,
		ft_nb_length(c.type.ui)));
		ft_putnbr_u_fd(c.type.ui, 1);
	}
	else if (*(c.conv) == 'x' || *(c.conv) == 'X')
	{
		ft_char_times('0', ft_zeros_spaces(c.values.zero_value,
		ft_hex_len(c.type.ui)));
		ft_to_hex(c.type.ui, *(c.conv));
	}
	else if (*(c.conv) == '%')
	{
		ft_char_times('0', ft_zeros_spaces(c.values.zero_value, 1));
		ft_putchar_fd('%', 1);
	}
}

void		ft_zero_process(t_format_container c)
{
	if (c.values.zero_value >= 0 && !c.mins)
		positive_zero(c);
}
