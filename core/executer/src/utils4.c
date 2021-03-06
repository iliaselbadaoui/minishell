/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:21:33 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/28 16:25:18 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

int	get_error(int ret)
{
	g_container->error = ret;
	if (ret == -1)
		g_container->error = 0;
	if (ret == 255)
	{
		ret = -1;
		g_container->error = 255;
	}
	return (ret);
}

// Signal handler: ctrl+c
void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		g_container->is_segint = 1;
		out("\n\033[32mminishell$ \033[37m");
		if (g_container->res)
		{
			free(g_container->res);
			g_container->res = NULL;
		}
	}
}

// Signals handler: ctrl+c inside a process
void	proc_signal_handler(int signo)
{
	if (signo == SIGQUIT && g_container->is_process)
		write(1, "Quit\n", 5);
}

// Returns all paths from PATH environment variable
t_string	*get_paths(void)
{
	t_map		*tmp;
	t_string	*path;

	tmp = g_container->map;
	path = ft_split(get_value_by_key(tmp, "PATH"), ':');
	return (path);
}
