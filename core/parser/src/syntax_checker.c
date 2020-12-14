/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:23:33 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/14 13:34:55 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int				syntax_checker(t_string line)
{
	while (line[g_counter])
	{
		if (!check_args(line) || !check_file(line))
		{
			out("minishell : syntax error near unexpected token `");
			out(g_err_msg);
			out("`\n");
			return (1);
		}
	}
	return (0);
}
