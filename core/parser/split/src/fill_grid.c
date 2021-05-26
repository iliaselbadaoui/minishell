/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 20:51:01 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/26 17:07:09 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_split.h"

static int	copy_to_next_delimiter(char *grid_case, char *str, char delimiter)
{
	int		count;

	count = 0;
	if (!grid_case)
		return (0);
	if (!g_container->flag)
	{
		while (str[count] && str[count] != delimiter)
		{
			grid_case[count] = str[count];
			count++;
		}
		if (count)
			g_container->flag = 1;
	}
	else
	{
		while (str[count])
		{
			grid_case[count] = str[count];
			count++;
		}
	}
	grid_case[count] = '\0';
	return (count);
}

static int	copy_to_next_delimiter_split(char *grid_case, char *str,
char delimiter)
{
	int		count;

	count = 0;
	while (str[count] && str[count] != delimiter)
	{
		grid_case[count] = str[count];
		count++;
	}
	grid_case[count] = '\0';
	return (count);
}

void	fill_grid(char **arr, char *str, char delimiter)
{
	int		count;
	int		arr_index;

	if (!str || !arr)
		return ;
	arr_index = 0;
	while (*str)
	{
		escape_deilimter(&str, delimiter);
		count = copy_to_next_delimiter_split(arr[arr_index], str, delimiter);
		str += count;
		arr_index++;
	}
}

void	fill_grid_first(char **arr, char *str, char delimiter)
{
	int		count;
	int		arr_index;

	if (!str || !arr)
		return ;
	arr_index = 0;
	while (*str)
	{
		escape_deilimter(&str, delimiter);
		if (arr[arr_index])
			count = copy_to_next_delimiter(arr[arr_index], str, delimiter);
		str += count;
		arr_index++;
	}
	g_container->flag = 0;
}
