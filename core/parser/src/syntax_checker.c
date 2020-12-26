/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:23:33 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/26 12:19:59 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool			syntax_checker(t_string line)
{
	g_flag = 0;
	g_counter = 0;
	if (!line)
		return (true);
	while (line[g_counter])
	{
		if (!check_args(line) || !check_file(line) ||
		!semi_colone_pipe_checker(line))
		{
			out("minishell : syntax error\n");
			if (g_error != NO_FILE_DIR)
				g_error = SYNTAX_ERROR;
			return (false);
		}
	}
	return (true);
}
