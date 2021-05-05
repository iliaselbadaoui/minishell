/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:48:58 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/05 15:58:33 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

void	handle_pipes(t_command **list)
{
	int			id;
	pid_t		pid;
	t_command	*cmd;

	cmd = *list;
	id = cmd->id;
	while (cmd->next->id == id)
	{
		//FORK HERE
		pid = fork();
		if (!pid)
		{
			// redriections in pipes here
			printf("Child\n");
		}
		else if (pid > 0)
		{
			wait(NULL);
			printf("Parent\n");
		}
		if (!(cmd->next))
			break ;
		cmd = cmd->next;
	}
}
