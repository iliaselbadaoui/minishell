/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:47:58 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/26 17:05:56 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_split.h"

char	**ft_split(char *str, char delimiter)
{
	char	**res;
	int		count;

	if (!str)
		return (NULL);
	count = ft_count(str, delimiter) + 1;
	if (count)
	{
		res = (char **)malloc(count * sizeof(char *));
		if (!res)
			return (NULL);
	}
	else
		return (NULL);
	res[count - 1] = NULL;
	create_grid(res, str, delimiter);
	fill_grid(res, str, delimiter);
	return (res);
}

char	**ft_split_first(char *str, char delimiter)
{
	char	**res;
	int		count;

	if (!str)
		return (NULL);
	count = 3;
	res = (char **)malloc(count * sizeof(char *));
	if (!res)
		return (NULL);
	res[0] = NULL;
	res[1] = NULL;
	res[2] = NULL;
	create_grid_first(res, str, delimiter);
	if (res[1] == NULL)
	{
		res[1] = malloc(1);
		res[1][0] = 0;
	}
	g_container->flag = 0;
	fill_grid_first(res, str, delimiter);
	return (res);
}
