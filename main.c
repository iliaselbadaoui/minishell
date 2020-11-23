/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 14:25:39 by ielbadao          #+#    #+#             */
/*   Updated: 2020/10/29 09:16:51 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/parser/parser.h"
#include "get_next_line.h"

int		main(int argc, char **argv, char **envp)
{
	char	*line;
	// char	**paths;
	t_part	*parts;
	int		flag;

	flag = 0;
	g_path = envp;
	while (!flag)
	{
		// still redirections and \\ and ENV
		ft_printf("minishell ➜ ");
		get_next_line(0, &line);
		parts = parser(line);
<<<<<<< HEAD
		ft_printf("%s", parts->command);
=======
		paths = get_path();
		int i = 0;
		while (!get_dir(paths[i], parts->command) && paths[i])
		{
			i++;
		}
		ft_printf("\nHERE found\n");
		free_double_char_arr(paths);
>>>>>>> e6d09a4840205c79391067ab48c61631a3c7273a
		free(line);
	}
	return (0);
}
