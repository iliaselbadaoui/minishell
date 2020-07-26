/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 20:27:56 by ielbadao          #+#    #+#             */
/*   Updated: 2019/12/05 20:34:22 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_pos_help(t_format_container c)
{
	if (*(c.conv) == 's')
	{
		if (c.type.s)
		{
			ft_char_times(' ', ft_zeros_spaces(c.values.star_value,
			ft_strlen(c.type.s)));
			ft_putstr_fd(c.type.s, 1, ft_strlen(c.type.s));
		}
		else
		{
			ft_char_times(' ', ft_zeros_spaces(c.values.star_value, 6));
			ft_putstr_fd("(null)", 1, 6);
		}
	}
}

void	ft_neg_help(char c, t_type t, t_values v)
{
	if (c == 's')
	{
		if (t.s)
		{
			ft_putstr_fd(t.s, 1, ft_strlen(t.s));
			ft_char_times(' ', ft_zeros_spaces(ft_abs(v.star_value),
			ft_strlen(t.s)));
		}
		else
		{
			ft_putstr_fd("(null)", 1, 6);
			ft_char_times(' ', ft_zeros_spaces(ft_abs(v.star_value), 6));
		}
	}
}
