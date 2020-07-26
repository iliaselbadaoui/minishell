/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:02:54 by ielbadao          #+#    #+#             */
/*   Updated: 2019/12/05 16:09:55 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_processor(t_format_container c)
{
	if ((c.zero || c.star) && (c.prec || c.prec_no_spec))
		ft_mixed_flags(c);
	else if (c.prec && *(c.conv) != 'p' && *(c.conv) != 'c')
		ft_point_process(c);
	else if (c.prec_no_spec)
		ft_null_prec(c);
	else if (c.zero || (c.zero && c.mins))
		ft_zero_process(c);
	else if (c.star || (c.star && c.mins))
		ft_star_process(c);
	else
		ft_print_type(c.type, *(c.conv));
}
