/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:45:13 by ielbadao          #+#    #+#             */
/*   Updated: 2020/11/25 12:42:38 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_split.h"

static int			copy_to_next_delimiter(char *grid_case, char *str, char delimiter)
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
		count =	copy_to_next_delimiter(arr[arr_index], str, delimiter);
		str += count;
		arr_index++;
	}
}
