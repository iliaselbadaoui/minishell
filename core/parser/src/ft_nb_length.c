/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:47:13 by ielbadao          #+#    #+#             */
/*   Updated: 2019/11/26 05:25:43 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_nb_length(long long int nb)
{
	unsigned int	len;

	if (!nb)
		return (1);
	len = 0;
	if (nb < 0)
		len++;
	while ((nb / 10))
	{
		nb /= 10;
		len++;
	}
	if ((nb % 10))
		len++;
	return (len);
}
