/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:59:35 by ielbadao          #+#    #+#             */
/*   Updated: 2019/10/25 23:15:43 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s1;
	char	*s2;
	int		i;

	if ((!dst && !src) || dst == src)
		return (0);
	i = 0;
	s1 = (char *)dst;
	s2 = (char *)src;
	while (i < (int)n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}
