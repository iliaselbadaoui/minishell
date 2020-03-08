/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:58:01 by ielbadao          #+#    #+#             */
/*   Updated: 2019/10/14 20:58:04 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (!s || (int)start > ft_strlen(s))
	{
		res = (char *)malloc(1);
		*res = '\0';
		return (res);
	}
	if (!(res = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	s += start;
	i = 0;
	while (i < len)
	{
		res[i] = *s;
		i++;
		s++;
	}
	res[i] = '\0';
	return (res);
}
