/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:23:33 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/12 23:19:10 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int				syntax_checker(t_string line)
{
	if (!check_args(line))
	{
		out("minishell : syntax error : quote not closed\n");
		return (1);
	}
	return (0);
}
