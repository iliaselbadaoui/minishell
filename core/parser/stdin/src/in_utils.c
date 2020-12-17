/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 13:32:25 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/17 13:32:44 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../in.h"

char		*ft_strchr(const char *s, int c)
{
	char *res;

	res = NULL;
	while (*s)
	{
		if (*s == c)
			return (res = (char *)s);
		s++;
	}
	return (NULL);
}

int			ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char		*ft_strjoin(char const *s1, char const *s2)
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

char		*ft_strdup(const char *s)
{
	int			len;
	int			i;
	char		*dst;

	i = -1;
	len = ft_strlen(s);
	if ((dst = (char *)malloc(len + 1)))
	{
		while (s[++i])
		{
			dst[i] = s[i];
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}

void		ft_free(char **p)
{
	if (*p != 0)
		free(*p);
	*p = 0;
}
