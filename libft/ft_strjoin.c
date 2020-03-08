/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:37:45 by ielbadao          #+#    #+#             */
/*   Updated: 2019/10/16 11:44:09 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(new = (char *)malloc(len * sizeof(char))))
		return (NULL);
	len = 0;
	while (*s1)
		new[len++] = *(s1++);
	while (*s2)
		new[len++] = *(s2++);
	new[len] = '\0';
	return (new);
}
