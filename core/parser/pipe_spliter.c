/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_spliter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:59:49 by ielbadao          #+#    #+#             */
/*   Updated: 2020/07/02 11:08:09 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

int		check_after_semicolone(char *string)
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
		if (*string != ';')
			count++;
		if (*string)
			string++;
	}
	return (count);
}

int		pipe_count(char *string)
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
		if (*string != ';' && *string != '"' && *string != 39 && !flag)
		{
			count++;
			flag = 1;
		}
		if (*string == ';' && check_after_semicolone(string+1))
			count++;
		if (*string)
			string++;
	}
	return (count);
}
int		find_semicolone(char *string)
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
		else if (*string != ';')
			len++;
		else
			return (len);
		if (*string)
			string++;
	}
	return (len);
}

char		*get_pipe(char *string, int *shift)
{
	char	*pipe;
	int		count;
	int		index;

	index = 0;
	count = find_semicolone(string);
	if (count < (int)length(string))
		string[count-1] = '\0';
	if (count)
	{
		pipe = (char *)malloc(count);
		*shift = count+1;
	}
	else
		return (NULL);
	while (index < count)
	{
		pipe[index] = string[index];
		index++;
	}
	pipe[index] = '\0';
	return (pipe);
}

char		**pipes(char *string)
{
	char	**res;
	int		count;
	int		index;
	int		shift;

	index = 0;
	count = pipe_count(string)+1;
	if (count)
		res = (char **)malloc(sizeof(char *)*(count));
	else
		return (NULL);
	while (*string != '0' && index < count-1)
	{
		shift = 0;
		res[index] = get_pipe(string, &shift);
		string += shift;
		index++;
	}
	res[index] = NULL;
	return (res);
}
