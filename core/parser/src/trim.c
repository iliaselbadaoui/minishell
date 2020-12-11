/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:04:52 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/11 12:39:12 by ielbadao         ###   ########.fr       */
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
	string[end + 1] = '\0';
	return (string);
}
