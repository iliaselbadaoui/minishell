/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_spliter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:59:49 by ielbadao          #+#    #+#             */
/*   Updated: 2020/07/02 11:04:19 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

int		check_after_vertical_bar(char *string)
{
	int	count;

	count = 0;
	while (*string)
	{
		while (*string == ' ')
			string++;
		if (*string == '"' || *string == 39)
		{
			count++;
			string++;
			while (*string && *string != '"' && *string != 39)
				string++;
		}
		if (*string != '|')
			count++;
		if (*string)
			string++;
	}
	return (count);
}

int		part_count(char *string)
{
	int		count;
	int		flag;
	char	quote;

	count = 0;
	flag = 0;
	while (*string)
	{
		while (*string == ' ')
			string++;
		if (*string == '"' || *string == 39)
		{
			if (!flag)
			{
				count++;
				flag = 1;
			}
			quote = *string;
			string++;
			while (*string && *string != quote)
				string++;
		}
		if (*string != '|' && *string != '"' && *string != 39 && !flag)
		{
			count++;
			flag = 1;
		}
		if (*string == '|' && check_after_vertical_bar(string+1))
			count++;
		if (*string)
			string++;
	}
	return (count);
}
int		find_vertical_bar(char *string)
{
	int		len;
	char	quote;

	len = 0;
	while (*string)
	{
		if (*string == '"' || *string == 39)
		{
			quote = *string;
			string++;
			len += 2;
			while (*string && *string != quote)
			{
				len++;
				string++;
			}
		}
		else if (*string != '|')
			len++;
		else
			return (len);
		if (*string)
			string++;
	}
	return (len);
}

char		*get_part(char *string, int *shift)
{
	char	*parts;
	int		count;
	int		index;

	index = 0;
	count = find_vertical_bar(string);
	if (count < (int)length(string))
		string[count-1] = '\0';
	if (count)
	{
		parts = (char *)malloc(count);
		*shift = count+1;
	}
	else
		return (NULL);
	while (index < count)
	{
		parts[index] = string[index];
		index++;
	}
	parts[index] = '\0';
	return (parts);
}

char		**parts(char *string)
{
	char	**res;
	int		count;
	int		index;
	int		shift;

	index = 0;
	if (*string == '|')
	{
		ft_printf("minishell: parse error near `|'\n");
		// SEGFAULT HERE
	}
	count = part_count(string) + 1;
	if (count)
		res = (char **)malloc(sizeof(char *)*count);
	else
		return (NULL);
	while (*string != '0' && index < count-1)
	{
		shift = 0;
		res[index] = get_part(string, &shift);
		string += shift;
		index++;
	}
	res[index] = NULL;
	return (res);
}
