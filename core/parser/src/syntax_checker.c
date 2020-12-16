/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:23:33 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/16 09:38:46 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_bool			syntax_checker(t_string line)
{
	while (line[g_counter])
	{
		if (!check_args(line) || !check_file(line) || 
			!semi_colone_pipe_checker(line))
		{
			out("minishell : syntax error\n");
			g_error = SYNTAX_ERROR;
			return (false);
		}
	}
	return (true);
}
