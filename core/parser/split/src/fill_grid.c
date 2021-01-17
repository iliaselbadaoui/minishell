/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:45:13 by ielbadao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/01/18 00:28:38 by ielbadao         ###   ########.fr       */
=======
/*   Updated: 2021/01/06 10:35:57 by ielbadao         ###   ########.fr       */
>>>>>>> 828092d177da354b40d7381cbafff2f609711962
/*                                                                            */
/* ************************************************************************** */

#include "../ft_split.h"

static int			copy_to_next_delimiter(char *grid_case, char *str,
char delimiter)
{
	int		count;

	count = 0;
	if (!g_flag)
	{
		while (str[count] && str[count] != delimiter)
		{
			grid_case[count] = str[count];
			count++;
		}
		if (count)
			g_flag = 1;
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
		count = copy_to_next_delimiter(arr[arr_index], str, delimiter);
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
		count =	copy_to_next_delimiter(arr[arr_index], str, delimiter);
		str += count;
		arr_index++;
	}
	g_flag = 0;
}