/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:21:33 by mait-si-          #+#    #+#             */
/*   Updated: 2021/04/14 16:52:59 by mait-si-         ###   ########.fr       */
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

// Create all files
void	init_files(t_redirect *tmp)
{
	int fd;

	while (tmp->file_name)
	{
		// Check redirection type
		fd = open(tmp->file_name, O_RDWR|O_CREAT, 0666);
		close(fd);
		tmp++;
	}
}
