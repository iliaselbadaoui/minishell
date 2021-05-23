/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:32:12 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 13:04:53 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static int	len(int nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return ((int)(size + 1));
}

static void	itoa_help(int *n, unsigned int *nb, unsigned int *size,
	unsigned int *i)
{
	if (*n < 0)
		*nb = *n * -1;
	else
		*nb = *n;
	*size = len(*nb);
	*i = 0;
	*n = 0;
	if (*n < 0)
		*n = 1;
}

t_string	ft_itoa(int n)
{
	char			*arr;
	unsigned int	nb;
	unsigned int	i;
	unsigned int	size;

	itoa_help(&n, &nb, &size, &i);
	arr = malloc(size + 1 + n);
	if (arr == 0)
		return (0);
	if (n < 0)
	{
		arr[i] = '-';
		size++;
	}
	i = size - 1;
	while (nb >= 10)
	{
		arr[i--] = (nb % 10 + 48);
		nb /= 10;
	}
	arr[i] = (nb % 10 + 48);
	arr[size] = '\0';
	return (arr);
}
