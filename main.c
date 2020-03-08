/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 18:20:39 by ielbadao          #+#    #+#             */
/*   Updated: 2020/03/08 11:30:38 by ielbadao         ###   ########.fr       */
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
		ft_printf("minishell:$> ");
		get_next_line(0, &line);
		signal = line_parser(line);
		free(line);
	}
	return (SUCCESS);
}
