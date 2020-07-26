/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mixed_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:51:43 by ielbadao          #+#    #+#             */
/*   Updated: 2019/12/06 15:33:24 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		activate_star(t_format_container *c)
{
	if (c->prec_no_spec)
	{
		c->prec = 1;
		c->values.prec_value = 0;
	}
	if (c->zero && !c->star)
	{
		c->star = 1;
		c->values.star_value = c->values.zero_value;
	}
	if (c->mins && c->values.star_value > 0)
		c->values.star_value *= -1;
}

static void		first(t_format_container c)
{
	if (c.values.star_value <= c.values.prec_value && !*(c.conv))
		ft_point_process(c);
	else
	{
		ft_print_exact_spaces(c);
		ft_point_process(c);
	}
}

static void		second(t_format_container c)
{
	if (ft_abs(c.values.star_value) <= c.values.prec_value)
		ft_point_process(c);
	else
	{
		ft_point_process(c);
		ft_print_exact_spaces(c);
	}
}

static void		percent_conv(t_format_container c)
{
	if (c.zero && c.values.prec_value >= 0 && c.values.zero_value > 0)
		ft_zero_process(c);
	else if (c.values.prec_value >= 0 && c.values.star_value <= 0)
		ft_star_process(c);
	else if (c.values.prec_value >= 0 && c.values.star_value > 0)
		ft_star_process(c);
	else if (c.values.prec_value < 0)
		ft_star_process(c);
}

void			ft_mixed_flags(t_format_container c)
{
	activate_star(&c);
	if (c.zero && c.values.prec_value < 0 && c.values.zero_value > 0)
		ft_zero_process(c);
	else if (*(c.conv) == '%')
		percent_conv(c);
	else if (c.zero && c.values.prec_value < 0 && c.values.zero_value <= 0)
		ft_star_process(c);
	else if (c.values.star_value >= 0 && c.values.prec_value >= 0)
		first(c);
	else if (c.values.star_value <= 0 && c.values.prec_value >= 0)
		second(c);
	else if (c.values.prec_value < 0)
		ft_star_process(c);
}
