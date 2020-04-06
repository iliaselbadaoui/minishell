/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:20:39 by ielbadao          #+#    #+#             */
/*   Updated: 2020/04/06 12:18:03 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int		main(void)
{
	int			signal;
	t_string	line;

	signal = 1;
	while (signal)
	{
		line = (t_string)malloc(400);
		ft_colored_output(CYAN, "minishell$> ");
		get_next_line(1, &line);
		signal = line_parser(line);
		free(line);
	}
	return (SUCCESS);
}
