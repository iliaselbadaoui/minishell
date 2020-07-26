/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mix_help_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:47:58 by ielbadao          #+#    #+#             */
/*   Updated: 2019/12/06 13:53:22 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_help_1_2(t_format_container c)
{
	if (c.type.l != 0 && ft_type_len(c.type, *(c.conv)) >= c.values.prec_value)
		ft_char_times(' ', c.values.star_value - ft_type_len(c.type,
		*(c.conv)) - 2);
	else
		ft_char_times(' ', c.values.star_value - c.values.prec_value - 2);
}

void	ft_help_2_2(t_format_container c)
{
	if (c.type.l != 0 && ft_type_len(c.type, *(c.conv)) >= c.values.prec_value)
		ft_char_times(' ', ft_abs(c.values.star_value) - ft_type_len(c.type,
		*(c.conv)) - 2);
	else
		ft_char_times(' ', ft_abs(c.values.star_value) - c.values.prec_value
		- 2);
}
