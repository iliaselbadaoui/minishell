/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 14:25:39 by ielbadao          #+#    #+#             */
/*   Updated: 2020/07/14 23:50:34 by ielbadao         ###   ########.fr       */
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
		ft_printf("minishell ➜ ");
		get_next_line(0, &line);
		parts = parser(line);
		ft_printf("%s", parts->command);
		free(line);
	}
	return (0);
}
