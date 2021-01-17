/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:12:46 by ielbadao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/01/18 00:29:34 by ielbadao         ###   ########.fr       */
=======
/*   Updated: 2021/01/06 10:39:34 by ielbadao         ###   ########.fr       */
>>>>>>> 828092d177da354b40d7381cbafff2f609711962
/*                                                                            */
/* ************************************************************************** */

#include "core/executer/executer.h"
#include <string.h>
#include <stdio.h>

int		main(int argc, t_string *argv, t_string *envp)
{
	t_string	line;
	t_command	*list;
	t_map		*map;

	map = fill_env(envp);
	if (argc && argv)
	{
		while (1)
		{
			out("minishell$ ");
			in(0, &line);
			if (syntax_checker(trim(line)))
			{
				list = parser(trim(line));
<<<<<<< HEAD
				// YOUR EXECUTION FUNCTION HERE LIKE => execute(list);
=======
				/*YOUR EXECUTION FUNCTION HERE*/
>>>>>>> 828092d177da354b40d7381cbafff2f609711962
			}
			free(line);
			free_commands(&list);
		}
	}
	free_map(&map);
	return (0);
}
