/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:59:42 by ielbadao          #+#    #+#             */
/*   Updated: 2020/01/06 11:36:04 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_fill_type(char conv, t_format_container *container,
			va_list *args)
{
	if (conv == 'i' || conv == 'd')
	{
		container->type.i = va_arg(*args, int);
	}
	else if (conv == 'x' || conv == 'X' || conv == 'u')
	{
		container->type.ui = va_arg(*args, unsigned int);
	}
	else if (conv == 'p')
	{
		container->type.l = va_arg(*args, size_t);
	}
	else if (conv == 'c')
	{
		container->type.c = va_arg(*args, int);
	}
	else if (conv == 's')
	{
		container->type.s = va_arg(*args, char *);
	}
}

static int	ft_get_value(char *format, va_list *args)
{
	int res;

	res = 0;
	if (*format == '*' || (*format == '0' && *(format + 1) == '*'))
	{
		res = va_arg(*args, int);
	}
	else if (*(format) >= '0' && *(format) <= '9')
	{
		res = ft_atoi(format);
	}
	return (res);
}

static int	ft_help2(char *format, t_format_container *container,
		va_list *args)
{
	if (*format == '-')
	{
		container->mins = 1;
		return (1);
	}
	else if (*format == '0' && !container->zero && !container->mins)
	{
		container->zero = 1;
		container->values.zero_value = ft_get_value((format + 1), args);
		return (1);
	}
	return (0);
}

static int	ft_finder_help(char *format, t_format_container *container,
	va_list *args)
{
	if (ft_help2(format, container, args))
		return (1);
	else if ((*format == '*' || (*(format) >= '0' && *(format) <= '9'))
			&& !container->star && !container->prec && !container->zero)
	{
		container->star = 1;
		container->values.star_value = ft_get_value(format, args);
		return (1);
	}
	else if (*format == '.' && !container->prec && !container->prec_no_spec &&
		*(format + 1) != '*' && (*(format + 1) < '0' || *(format + 1) > '9'))
	{
		container->prec_no_spec = 1;
		return (1);
	}
	else if (*format == '.' && !container->prec && !container->prec_no_spec)
	{
		container->prec = 1;
		container->values.prec_value = ft_get_value((format + 1), args);
		return (1);
	}
	return (0);
}

int			ft_finder(char *format, t_format_container *container,
			va_list *args)
{
	int i;

	i = 0;
	while (*format)
	{
		ft_finder_help(format, container, args);
		if (ft_match_conversion(*format))
		{
			container->conv = format;
			ft_fill_type(*(container->conv), container, args);
			i++;
			break ;
		}
		format++;
		i++;
	}
	return (i);
}
