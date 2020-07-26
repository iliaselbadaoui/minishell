/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:03:29 by ielbadao          #+#    #+#             */
/*   Updated: 2019/12/01 14:27:16 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_putchar_fd(char c, int fd)
{
	static	int len;

	if (fd == 1)
	{
		write(fd, &c, 1);
		len++;
	}
	return (len);
}
