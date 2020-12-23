/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:12:46 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/23 16:30:08 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <string.h>
#include <stdio.h>
//int argc, t_string *argv, t_string *envp
int		main()
{
	// t_string	line;


	// if (argc && argv)
	// {
	// 	while (*envp)
	// 	{
	// 		printf("%s\n", *envp);
	// 		envp++;
	// 	}
	// }
	printf ("%d\n", sequence_calculator("ilias elbadaoui ; 'echo' hello \"word\" ; grep h", ';'));
	// while (1)
	// {
	// 	out("minishell$ ");
	// 	in(0, &line);
	// 	if (syntax_checker(trim(line)))
	// 	{
	// 		out("IT'S WORKING\n");
	// 	}
	// 	free(line);
	// 	line = NULL;
	// }
	return (0);
}
