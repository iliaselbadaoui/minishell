/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 12:00:28 by ielbadao          #+#    #+#             */
/*   Updated: 2019/12/06 13:11:13 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_null_prec(t_format_container c)
{
	if ((*(c.conv) == 'd' || *(c.conv) == 'i') && c.type.i != 0)
		ft_putnbr_fd(c.type.i, 1);
	else if (*(c.conv) == 'u' && c.type.ui > 0)
		ft_putnbr_u_fd(c.type.ui, 1);
	else if ((*(c.conv) == 'x' || *(c.conv) == 'X') && c.type.ui > 0)
		ft_to_hex(c.type.ui, *(c.conv));
	else if (*(c.conv) == 'c')
		ft_putchar_fd(c.type.c, 1);
	else if (*(c.conv) == 'p')
	{
		ft_putstr_fd("0x", 1, 2);
		if (c.type.l != 0)
			ft_to_phex(c.type.l);
	}
	else if (*(c.conv) == '%')
		ft_putchar_fd('%', 1);
}

static void	pos_help(t_format_container c)
{
	if (*(c.conv) == 'x' || *(c.conv) == 'X')
	{
		ft_char_times('0', ft_zeros_spaces(c.values.prec_value,
		ft_hex_len(c.type.ui)));
		ft_to_hex(c.type.ui, *(c.conv));
	}
	else if (*(c.conv) == 's')
	{
		if (c.type.s)
			ft_putstr_fd(c.type.s, 1, ft_printable_length(c.values.prec_value,
			ft_strlen(c.type.s)));
		else
			ft_putstr_fd("(null)", 1, ft_printable_length(c.values.prec_value,
			6));
	}
	else if (*(c.conv) == '%')
		ft_putchar_fd('%', 1);
}

static void	positive_prec(t_format_container c)
{
	if (c.type.i < 0)
		ft_putchar_fd('-', 1);
	if (*(c.conv) == 'i' || *(c.conv) == 'd')
	{
		ft_char_times('0', ft_zeros_spaces(c.values.prec_value,
		ft_nb_length(ft_abs(c.type.i))));
		ft_putnbr_fd(ft_abs(c.type.i), 1);
	}
	else if (*(c.conv) == 'u')
	{
		ft_char_times('0', ft_zeros_spaces(c.values.prec_value,
		ft_nb_length(c.type.ui)));
		ft_putnbr_u_fd(c.type.ui, 1);
	}
	else
		pos_help(c);
}

void		ft_point_process(t_format_container c)
{
	if (c.values.prec_value > 0)
	{
		positive_prec(c);
	}
	else if (c.values.prec_value == 0)
	{
		ft_null_prec(c);
	}
	else if (c.values.prec_value < 0)
		ft_print_type(c.type, *(c.conv));
}
