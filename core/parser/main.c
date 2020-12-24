/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:12:46 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/24 11:51:42 by ielbadao         ###   ########.fr       */
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
	// printf ("%d\n", sequence_calculator("ilias elbadaoui ; 'echo' hello \"word\" ; grep h", ';'));
	t_string *seq = spliter_grid("ilias elbadaoui ; 'echo' hello \"word\" ; grep h", ';');
	while (*seq)
	{
		printf("%s\n", trim(*seq));
		seq++;
	}
	
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
