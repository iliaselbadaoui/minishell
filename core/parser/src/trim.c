/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:04:52 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/10 14:47:05 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"
#include <stdio.h>

t_string		trim(t_string string)
{
	t_string	trimed;
	int			start;
	int			end;
	
	start = 0;
	end = length(string);
	if (!string || !(end - 1))
	 return (NULL);
	while (string[start] == ' ' && string[start])
		start++;
	string += start;
	out(string);
	out("|\n");
	end -= 1;
	printf("AT END : %c|\n", string[end]);
	while (string[end] == ' ')
		end--;
	// string[end + 1] = '\0';
	printf("END :%d\n", end);
	trimed = NULL;
	return (trimed);
}
