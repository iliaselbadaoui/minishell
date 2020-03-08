/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 00:37:37 by ielbadao          #+#    #+#             */
/*   Updated: 2019/10/25 23:15:14 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		d;
	size_t		len;

	len = ft_strlen(src);
	i = 0;
	if (!dst && !size)
		return (len);
	while (*dst != '\0' && i < size)
	{
		dst++;
		i++;
	}
	d = size - i;
	if (d == 0)
		return (i + ft_strlen(src));
	while (*src != '\0' && d != 1)
	{
		*dst++ = *src;
		d--;
		src++;
	}
	*dst = '\0';
	return (i + len);
}
