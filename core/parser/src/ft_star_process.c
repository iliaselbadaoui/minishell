/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:30:38 by ielbadao          #+#    #+#             */
/*   Updated: 2019/12/06 13:53:38 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	positive_star2(t_format_container c)
{
	if (*(c.conv) == 'p')
	{
		ft_char_times(' ', ft_zeros_spaces(c.values.star_value,
		ft_hex_len(c.type.l) + 2));
		ft_putstr_fd("0x", 1, 2);
		ft_to_phex(c.type.l);
	}
	else if (*(c.conv) == 'c')
	{
		ft_char_times(' ', ft_zeros_spaces(c.values.star_value, 1));
		ft_putchar_fd(c.type.c, 1);
	}
	else
		ft_pos_help(c);
}

static void	positive_star(t_format_container c)
{
	if (*(c.conv) == 'i' || *(c.conv) == 'd')
	{
		ft_char_times(' ', ft_zeros_spaces(c.values.star_value,
		ft_nb_length(c.type.i)));
		ft_putnbr_fd(c.type.i, 1);
	}
	else if (*(c.conv) == 'u')
	{
		ft_char_times(' ', ft_zeros_spaces(c.values.star_value,
		ft_nb_length(c.type.ui)));
		ft_putnbr_u_fd(c.type.ui, 1);
	}
	else if (*(c.conv) == 'x' || *(c.conv) == 'X')
	{
		ft_char_times(' ', ft_zeros_spaces(c.values.star_value,
		ft_hex_len(c.type.ui)));
		ft_to_hex(c.type.ui, *(c.conv));
	}
	else if (*(c.conv) == '%')
	{
		ft_char_times(' ', ft_zeros_spaces(c.values.star_value, 1));
		ft_putchar_fd('%', 1);
	}
	else
		positive_star2(c);
}

static void	negative_star2(char c, t_type t, t_values v)
{
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1, 2);
		ft_to_phex(t.l);
		ft_char_times(' ', ft_zeros_spaces(ft_abs(v.star_value),
		ft_hex_len(t.l) + 2));
	}
	else if (c == 'c')
	{
		ft_putchar_fd(t.c, 1);
		ft_char_times(' ', ft_zeros_spaces(ft_abs(v.star_value), 1));
	}
	else
		ft_neg_help(c, t, v);
}

void		ft_negative_star(char c, t_type t, t_values v)
{
	if (c == 'i' || c == 'd')
	{
		ft_putnbr_fd(t.i, 1);
		ft_char_times(' ', ft_zeros_spaces(ft_abs(v.star_value),
		ft_nb_length(t.i)));
	}
	else if (c == 'u')
	{
		ft_putnbr_u_fd(t.ui, 1);
		ft_char_times(' ', ft_zeros_spaces(ft_abs(v.star_value),
		ft_nb_length(t.ui)));
	}
	else if (c == 'x' || c == 'X')
	{
		ft_to_hex(t.ui, c);
		ft_char_times(' ', ft_zeros_spaces(ft_abs(v.star_value),
		ft_hex_len(t.ui)));
	}
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		ft_char_times(' ', ft_zeros_spaces(ft_abs(v.star_value), 1));
	}
	else
		negative_star2(c, t, v);
}

void		ft_star_process(t_format_container c)
{
	if (c.values.star_value > 0 && !c.mins)
		positive_star(c);
	else if (c.values.star_value > 0 || c.values.star_value <= 0 || !c.mins)
		ft_negative_star(*(c.conv), c.type, c.values);
}
