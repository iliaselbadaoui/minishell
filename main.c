/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 14:25:39 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/08 11:37:21 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/parser/parser.h"
#include "get_next_line.h"

int		main(int argc, char **argv, char **envp)
{
	char	*line;
	t_part	*parts;
	int		flag;

	if (argc && argv)
	{
		flag = 0;
		g_path = envp;
		while (!flag)
		{
			// still redirections and \\ and ENV
			ft_printf("minishell ➜ ");
			get_next_line(0, &line);
			parts = parser(line);
			ft_printf("%d\n",parts->pipe_id);
			parts = parts->next;
			ft_printf("%d\n",parts->pipe_id);
			parts = parts->next;
			ft_printf("%d\n",parts->pipe_id);
			g_pipe_id = 0;
			free(line);
		}
	}
	return (0);
}
