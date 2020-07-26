/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:23:38 by ielbadao          #+#    #+#             */
/*   Updated: 2019/12/06 10:36:43 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_type_len(t_type t, char c)
{
	if (c == 'i' || c == 'd')
		return (ft_nb_length(t.i));
	else if (c == 'u')
		return (ft_nb_length(t.ui));
	else if (c == 'x' || c == 'X')
		return (ft_hex_len(t.ui));
	else if (c == 'p')
		return (ft_hex_len(t.l));
	else if (c == 'c' || c == '%')
		return (1);
	else if (c == 's')
		return (ft_strlen(t.s));
	return (-1);
}
