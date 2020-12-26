/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:12:46 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/26 17:31:59 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <string.h>
#include <stdio.h>
//int argc, t_string *argv, t_string *envp
int		main()
{
	t_string	*args;
	t_string	*pipes;
	int 		counter=0;
	int 		counter_extra=0;

	args = spliter("echo ilias > 'ilias' | extra commands ; echo \"hello\"", ';');
	while (args[counter])
	{
		printf("PIPE : |%s|\n", args[counter]);
		pipes = spliter(args[counter], '|');
		while (pipes[counter_extra])
		{
			printf("Command : |%s|\n", pipes[counter_extra]);
			counter_extra++;
		}
		counter++;
	}
	return (0);
}
