/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:03:29 by ielbadao          #+#    #+#             */
/*   Updated: 2019/10/22 22:03:38 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find(const char *set, int c)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s, char const *set)
{
	int		beg;
	int		end;
	int		i;
	char	*p;

	beg = -1;
	if (!s)
		return (NULL);
	end = ft_strlen(s);
	while (s[++beg])
		if (!find(set, s[beg]))
			break ;
	while (beg < end - 1)
		if (!find(set, s[end - 1]))
			break ;
		else
			end--;
	if (!(p = malloc(end - beg + 1)))
		return (NULL);
	i = -1;
	while (++i < (end - beg))
		p[i] = s[beg + i];
	p[i] = '\0';
	return (p);
}
