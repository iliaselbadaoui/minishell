/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:17:21 by ielbadao          #+#    #+#             */
/*   Updated: 2019/11/23 16:14:05 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_handle_hex(int nb, char flag)
{
	if (nb <= 9)
		ft_putchar_fd('0' + nb, 1);
	else if (nb <= 15)
	{
		if (flag == 'x')
			ft_putchar_fd(87 + nb, 1);
		else
			ft_putchar_fd(55 + nb, 1);
	}
}

void		ft_to_hex(unsigned int nb, char flag)
{
	if (nb >= 16)
	{
		ft_to_hex((nb / 16), flag);
		ft_handle_hex((nb % 16), flag);
	}
	else
		ft_handle_hex(nb, flag);
}

int			ft_hex_len(size_t nb)
{
	int len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_hex_len(nb / 16);
		len++;
	}
	else
		len++;
	return (len);
}

void		ft_to_phex(size_t nb)
{
	if (nb >= 16)
	{
		ft_to_phex((nb / 16));
		ft_handle_hex((nb % 16), 'x');
	}
	else
		ft_handle_hex(nb, 'x');
}
