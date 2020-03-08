/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_times.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:07:20 by ielbadao          #+#    #+#             */
/*   Updated: 2020/03/07 18:33:07 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_times(char c, int times)
{
	while (times > 0)
	{
		ft_putchar_fd(c, 1);
		times--;
	}
}
