/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:57:53 by ielbadao          #+#    #+#             */
/*   Updated: 2021/01/18 00:11:27 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_split.h"

static int			count_to_next_delimiter(char *str, char delimiter)
{
	int				count;

	count = 0;
	if (!g_flag)
	{
		while (str[count] && str[count] != delimiter)
			count++;
		if (count)
			g_flag = 1;
	}
	else
		while (str[count])
			count++;
	return (count);
}

static void			free_grid(char **arr)
{
	while (*arr)
	{
		free(*arr);
		(*arr)++;
	}
	free(arr);
}

void				create_grid(char **arr, char *str, char delimiter)
{
	int		count;

	escape_deilimter(&str, delimiter);
	while (*str)
	{
		escape_deilimter(&str, delimiter);
		count = count_to_next_delimiter(str, delimiter);
		if (count)
		{
			if (!(*arr = (char *)malloc(count + 1)))
			{
				free_grid(arr);
				return ;
			}
			arr++;
		}
		else
			return ;
		str += count;
	}
}

void				create_grid_first(char **arr, char *str, char delimiter)
{
	int		count;

	escape_deilimter(&str, delimiter);
	while (*str)
	{
		escape_deilimter(&str, delimiter);
		count = count_to_next_delimiter(str, delimiter);
		if (count)
		{
			if (!(*arr = (char *)malloc(count + 1)))
			{
				free_grid(arr);
				return ;
			}
			arr++;
		}
		else
			return ;
		str += count;
	}
	g_flag = 0;
}
