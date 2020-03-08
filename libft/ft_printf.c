/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:33:27 by ielbadao          #+#    #+#             */
/*   Updated: 2019/12/04 16:53:32 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int					len;
	va_list				args;
	t_format_container	conatiner;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		ft_init_format(&conatiner);
		if (*format == '%' && ft_finder((char *)(format + 1), &conatiner,
			&args))
		{
			ft_processor(conatiner);
			format = conatiner.conv;
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	len = ft_putchar_fd(' ', 0);
	va_end(args);
	return (len);
}
