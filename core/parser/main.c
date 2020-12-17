/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:12:46 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/17 13:41:54 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <string.h>
#include <stdio.h>
int		main()
{
	// . ../ path/filename : should be handled
	// syntax_checker(strdup("ilias \"elbadaoui\" \"ilias"));
	t_string line;
	while (1)
	{
		out("minishell$ ");
		in(0, &line);
		if (syntax_checker(trim(line)))
		{
			out("IT'S WORKING\n");
		}
	}
	
	// if (syntax_checker(strdup(">>> \\;")))
	// {
	// 	out("IT'S WORKING");
	// }
	// if (check_file(">>>> ilias"))
	// 	printf("TRUE\n");
	// else
	// 	printf("FALSE\n");
	return (0);
}
