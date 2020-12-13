/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:23:33 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/13 13:08:33 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int				syntax_checker(t_string line)
{
	if (!check_args(line))
	{
		out("minishell : syntax error near unexpected token ");
		out(&g_char);
		out("\n");
		return (1);
	}
	return (0);
}
