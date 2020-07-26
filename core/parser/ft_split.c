/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 06:02:01 by ielbadao          #+#    #+#             */
/*   Updated: 2020/07/02 22:41:48 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static	int	wordcount(const char *str, char c)
{
	int word;
	int i;

	i = 0;
	word = 0;
	if (str[0] != c && str[0])
		word++;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			if (str[i + 1] != c && str[i + 1] != '\0')
				word++;
		}
		i++;
	}
	return (word);
}

static	int	wordlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	words = wordcount(s, c);
	tab = (char **)malloc(sizeof(*tab) * wordcount(s, c) + 1);
	if (tab == NULL)
		return (NULL);
	while (words--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_substr(s, 0, wordlen(s, c));
		if (tab[i] == NULL)
			return (NULL);
		s += wordlen(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
