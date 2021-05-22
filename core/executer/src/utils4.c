/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:21:33 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/22 15:19:08 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

int	get_error(int ret)
{
	g_error = ret;
	if (ret == -1)
		g_error = 0;
	if (ret == 255)
	{
		ret = -1;
		g_error = 255;
	}
	return (ret);
}

// Signal handler: ctrl+c
void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		out("\n\033[32mminishell$ \033[37m");
		signal(SIGINT, signal_handler);
	}
}

// Signals handler: ctrl+c inside a process
void	proc_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		out("\n");
		signal(SIGINT, proc_signal_handler);
	}
}
