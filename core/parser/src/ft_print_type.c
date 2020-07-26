/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:37:53 by ielbadao          #+#    #+#             */
/*   Updated: 2019/12/05 14:57:26 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_type(t_type t, char c)
{
	if (c == 'i' || c == 'd')
		ft_putnbr_fd(t.i, 1);
	else if (c == 'u')
		ft_putnbr_u_fd(t.ui, 1);
	else if (c == 'x' || c == 'X')
		ft_to_hex(t.ui, c);
	else if (c == 'p')
	{
		ft_putstr_fd("0x", 1, 2);
		ft_to_phex(t.l);
	}
	else if (c == 'c')
		ft_putchar_fd(t.c, 1);
	else if (c == 's')
	{
		if (t.s)
			ft_putstr_fd(t.s, 1, ft_strlen(t.s));
		else
			ft_putstr_fd("(null)", 1, ft_strlen("(null)"));
	}
	else if (c == '%')
		ft_putchar_fd('%', 1);
}
