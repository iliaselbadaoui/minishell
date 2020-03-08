/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:03:29 by ielbadao          #+#    #+#             */
/*   Updated: 2019/10/22 22:03:38 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		len(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return (int)(size + 1);
}

char			*ft_itoa(int n)
{
	char			*arr;
	unsigned int	nb;
	unsigned int	i;
	unsigned int	size;

	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	size = len(nb);
	i = 0;
	arr = malloc(size + 1 + (n < 0 ? 1 : 0));
	if (arr == 0)
		return (0);
	if (n < 0 && (arr[i] = '-'))
		size++;
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
