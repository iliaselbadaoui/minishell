/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:04:52 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/26 12:20:22 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_string		trim(t_string string)
{
	int			start;
	int			end;

	start = 0;
	end = length(string);
	if (!string || !end)
		return (NULL);
	while (string[start] == ' ' && string[start])
		start++;
	string += start;
	end = length(string) - 1;
	while (string[end] == ' ')
	{
		if (string[end - 1] != 92)
			end--;
		else
			break ;
	}
	if (string[end] != '\\')
		string[end + 1] = '\0';
	else
		string[end + 2] = '\0';
	return (string);
}
