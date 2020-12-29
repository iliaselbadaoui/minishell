/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:35:56 by ielbadao          #+#    #+#             */
/*   Updated: 2020/11/25 12:42:38 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_split.h"

void	escape_deilimter(char **str, char delimiter)
{
	while (**str == delimiter)
		(*str)++;
}

int		ft_count(char *str, char delimiter)
{
	int		count;

	count = 0;
	escape_deilimter(&str, delimiter);
	while (*str)
	{
		if (*str == delimiter)
		{
			escape_deilimter(&str, delimiter);
			if (*str)
				count++;
		}
		str++;
	}
	return (count + 1);
}
