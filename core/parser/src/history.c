/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:55:01 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/19 14:59:32 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int				history(void)
{
	t_string	termtype;
  	int			success;

	termtype = getenv("TERM");
	if (termtype == 0)
		out("Specify a terminal type with `setenv TERM <yourtype>'.\n");

	success = tgetent (g_term_buffer, termtype);
	if (success < 0)
		out("Could not access the termcap data base.\n");
	if (success == 0)
	{
		out("Terminal type `");
		out(termtype);
		out("' is not defined.\n");
	}
}
