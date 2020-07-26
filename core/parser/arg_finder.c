/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_finder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 00:18:18 by ielbadao          #+#    #+#             */
/*   Updated: 2020/06/30 15:28:59 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

char		*quote_extracter(char *string, char quote_char, int *i)
{
	char	*quote;
	int		count;

	if (!string)
		return (NULL);
	count = 0;	
	while (string[count] && string[count] != quote_char)
		count++;
	*i = count + 2;
	count++;
	if (!count || !(quote = (char *)malloc((count))))
		return (NULL);
	count = 0;
	while (string[count] && string[count] != quote_char)
	{
		quote[count] = string[count];
		count++;
		quote[count] = '\0';
	}
	return (quote);
}

char		*option_extracter(char *string, int *i)
{
	char	*quote;
	int		count;

	if (!string)
		return (NULL);
	count = 0;	
	while (string[count] && string[count] != ' ' && string[count] != '"' && string[count] != 39)
		count++;
	*i = count;
	if (!count || !(quote = (char *)malloc(count + 1)))
		return (NULL);
	count = 0;
	while (string[count] && string[count] != ' ')
	{
		quote[count] = string[count];
		count++;
	}
	quote[count] = '\0';
	return (quote);
}

int		count_args(char *cmd)
{
	int		count;
	int		resp;

	if (!cmd)
		return (0);
	count = 0;
	while (*cmd)
	{
		while (*cmd == ' ')
			cmd++;
		if (*cmd && *cmd != '"' && *cmd != 39)
		{
			if (option_extracter(cmd, &resp))
				count++;
			cmd += resp;
		}
		else if (*cmd && (*cmd == '"' || *cmd == 39))
		{
			if (quote_extracter(cmd+1, *cmd, &resp))
				count++;
			cmd += resp;
		}
	}
	return count;
}

char	**arg_finder(char *cmd)
{
	char	**args;
	int		resp;
	int		i;

	if (!cmd)
		return (NULL);
	if (!(args = (char **)malloc(sizeof(char *)*(count_args(cmd)+1))))
		return (NULL);
	i = 0;
	while (*cmd)
	{
		while (*cmd == ' ')
			cmd++;
		if (*cmd && *cmd != '"' && *cmd != 39)
		{
			if ((args[i] = option_extracter(cmd, &resp)))
				i++;
		}
		else if (*cmd && (*cmd == '"' || *cmd == 39))
		{
			if ((args[i] = quote_extracter(cmd+1, *cmd, &resp)))
				i++;
		}
		cmd += resp;
	}
	args[i] = NULL;
	return (args);
}
