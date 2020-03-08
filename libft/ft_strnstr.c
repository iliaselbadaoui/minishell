/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:45:26 by ielbadao          #+#    #+#             */
/*   Updated: 2019/10/12 00:32:46 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	char		*hay;
	char		*need;
	size_t		j;

	hay = (char *)haystack;
	need = (char *)needle;
	i = 0;
	if (needle && !haystack && !len)
		return (NULL);
	if (*needle == '\0')
		return (hay);
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		if (hay[i] == need[j])
		{
			while (need[j] != '\0' && hay[i + j] == need[j] && i + j < len)
				j++;
			if (j == (size_t)ft_strlen(needle))
				return (&hay[i]);
		}
		i++;
	}
	return (NULL);
}
