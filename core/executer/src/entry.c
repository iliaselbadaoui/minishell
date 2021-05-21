/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:54:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/21 18:36:25 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

t_command	*init(t_command *list)
{
	t_command *head;

	head = list;
	while (list)
	{
		list->fd[0] = -1;
		list->fd[1] = -1;
		list->pid = -1;
		list = list->next;
	}
	return head;
}

// Execute all commands, separated by ";"
// return 0, -1 : SUCCESS
// return 1, 127, 255, ... : FAILED
int	exec_cmds(t_command *list)
{
	int	ret;

	ret = 0;
	list = init(list);
	// Loop through commands line (separated by ; )
	while (list)
	{
		// Check pipes
		if (list->next && list->id == list->next->id)
			list = handle_pipes(list);
		else
			ret = exec_command(list);
		list = list->next;
	}
	return (ret);
}
