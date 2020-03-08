/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 06:02:01 by ielbadao          #+#    #+#             */
/*   Updated: 2019/10/19 06:02:48 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			word_count(const char *s, char c)
{
	int count;
	int i;
	int wd;

	count = 0;
	wd = 0;
	i = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == c)
			wd = 0;
		else if (wd == 0)
		{
			wd = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static	int			max_word(const char *s, int i, char c)
{
	int len;
	int j;

	len = 0;
	j = i;
	i = 0;
	while (s[j] != c)
	{
		len++;
		j++;
	}
	return (len);
}

static	void		*mfree(char **words, int j)
{
	while (j--)
		free(words[j]);
	free(words);
	return (NULL);
}

static	char		**malloc_fill(const char *s, char c, char **words)
{
	int i;
	int k;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < word_count(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		words[j] = malloc(sizeof(char) * max_word(s, i, c) + 1);
		if (words[j] == NULL)
			return (mfree(words, j));
		while (s[i] != c)
			words[j][k++] = s[i++];
		words[j][k] = '\0';
		j++;
	}
	words[j] = 0;
	return (words);
}

char				**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = malloc(sizeof(char *) * word_count(s, c) + 1);
	if (!words)
		return (NULL);
	return (malloc_fill(s, c, words));
}
