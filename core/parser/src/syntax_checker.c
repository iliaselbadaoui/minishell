/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:23:33 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 16:50:18 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool	syntax_checker(t_string line)
{
	g_container->flag = 0;
	g_container->counter = 0;
	if (!line || !length(line))
		return (true);
	while (line[g_container->counter])
	{
		if (!check_args(line) || !check_file(line)
			|| !semi_colone_pipe_checker(line))
		{
			out("minishell : syntax error\n");
			if (g_container->error != NO_FILE_DIR)
				g_container->error = SYNTAX_ERROR;
			return (false);
		}
	}
	return (true);
}
