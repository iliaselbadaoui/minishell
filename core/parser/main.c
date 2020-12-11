/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:12:46 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/11 22:56:48 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <string.h>
#include <stdio.h>
int		main()
{
	// if (is_quote("\"ilias elbadaoui\""))
	// {
	// 	out("IT IS\n");
	// }
	// else
	// {
	// 	out("IT'S NOT\n");
	// }
	printf("%d", syntax_checker(">"));
	// t_string str = strdup("     ilias   \134      \0");
	// int i = 0;
	// while (1)
	// {
	// 	if (!i)
	// 		printf("|%s|",trim(str));
	// 	scanf("%d", &i);
	// 	free(str);
	// }
	
	return (0);
}
