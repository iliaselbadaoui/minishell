/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mix_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:33:30 by ielbadao          #+#    #+#             */
/*   Updated: 2019/12/06 14:18:00 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	help_1_1(t_format_container c)
{
	if (!c.values.prec_value)
	{
		if (*(c.conv) != 's')
		{
			if (*(c.conv) == 'c' || *(c.conv) == '%')
				ft_char_times(' ', c.values.star_value - 1);
			else if (c.type.i != 0 || c.type.ui != 0)
				ft_char_times(' ', c.values.star_value - ft_type_len(c.type,
				*(c.conv)));
			else
				ft_char_times(' ', c.values.star_value);
		}
		else
			ft_char_times(' ', c.values.star_value -
			ft_printable_length(c.values.prec_value, ft_strlen(c.type.s)));
	}
	else
	{
		if (*(c.conv) != 's')
			ft_char_times(' ', c.values.star_value -
			c.values.prec_value - 1);
		else
			ft_char_times(' ', c.values.star_value -
			ft_printable_length(c.values.prec_value, ft_strlen(c.type.s)));
	}
}

static void	help_1(t_format_container c)
{
	if (c.type.i > 0 && (ft_strchr("di", *(c.conv))) &&
		c.values.prec_value > 0)
		ft_char_times(' ', c.values.star_value - c.values.prec_value);
	else if (c.type.ui != 0 && ft_strchr("uxX", *(c.conv)))
	{
		if (ft_type_len(c.type, *(c.conv)) >= c.values.prec_value)
			ft_char_times(' ', c.values.star_value - ft_type_len(c.type,
			*(c.conv)));
		else
			ft_char_times(' ', c.values.star_value - c.values.prec_value);
	}
	else if (*(c.conv) == 'p')
		ft_help_1_2(c);
	else if ((c.type.i < 0) && (ft_strchr("di", *(c.conv))) &&
		c.values.prec_value > 0)
		ft_char_times(' ', c.values.star_value - c.values.prec_value - 1);
	else if ((c.type.i == 0 || c.type.ui == 0) && (ft_strchr("duixX",
			*(c.conv))) && c.values.prec_value > 0)
		ft_char_times(' ', c.values.star_value - c.values.prec_value);
	else
		help_1_1(c);
}

static void	help_2_1(t_format_container c)
{
	if (!c.values.prec_value)
	{
		if (*(c.conv) != 's')
		{
			if (*(c.conv) == 'c' || *(c.conv) == '%')
				ft_char_times(' ', ft_abs(c.values.star_value) - 1);
			else if (c.type.i != 0 || c.type.ui != 0)
				ft_char_times(' ', ft_abs(c.values.star_value) -
				ft_type_len(c.type, *(c.conv)));
			else
				ft_char_times(' ', ft_abs(c.values.star_value));
		}
		else
			ft_char_times(' ', ft_abs(c.values.star_value) -
			ft_printable_length(c.values.prec_value, ft_strlen(c.type.s)));
	}
	else
	{
		if (*(c.conv) != 's')
			ft_char_times(' ', ft_abs(ft_abs(c.values.star_value)) -
			c.values.prec_value - 1);
		else
			ft_char_times(' ', ft_abs(c.values.star_value) -
			ft_printable_length(c.values.prec_value, ft_strlen(c.type.s)));
	}
}

static void	help_2(t_format_container c)
{
	if (c.type.i > 0 && (ft_strchr("di", *(c.conv))) &&
		c.values.prec_value > 0)
		ft_char_times(' ', ft_abs(c.values.star_value) - c.values.prec_value);
	else if (c.type.ui != 0 && ft_strchr("uxX", *(c.conv)))
	{
		if (ft_type_len(c.type, *(c.conv)) >= c.values.prec_value)
			ft_char_times(' ', ft_abs(c.values.star_value) - ft_type_len(c.type,
			*(c.conv)));
		else
			ft_char_times(' ', ft_abs(c.values.star_value) -
			c.values.prec_value);
	}
	else if (ft_strchr("p", *(c.conv)))
		ft_help_2_2(c);
	else if ((c.type.i < 0) && (ft_strchr("di", *(c.conv))) &&
		c.values.prec_value > 0)
		ft_char_times(' ', ft_abs(c.values.star_value) -
		c.values.prec_value - 1);
	else if ((c.type.i == 0 || c.type.ui == 0) && (ft_strchr("duixX",
			*(c.conv))) && c.values.prec_value > 0)
		ft_char_times(' ', ft_abs(c.values.star_value) - c.values.prec_value);
	else
		help_2_1(c);
}

void		ft_print_exact_spaces(t_format_container c)
{
	if (c.values.star_value >= 0 && c.values.prec_value >= 0)
	{
		help_1(c);
	}
	else if (c.values.star_value <= 0 && c.values.prec_value >= 0)
	{
		help_2(c);
	}
}
