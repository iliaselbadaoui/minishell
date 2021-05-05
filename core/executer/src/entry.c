/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:54:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/05 17:48:24 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

// Execute all commands, separated by ";"
// return 0, -1 : SUCCESS
// return 1, 127, 255, ... : FAILED
int	exec_cmds(t_command *list)
{
	int			ret;
	int			fd_std[2];

	ret = 0;
	fd_std[0] = dup(0);
	fd_std[1] = dup(1);
	while (list)
	{
		// Check pipes
		// if (list->id == list->next->id)
		// 	handle_pipes(&list);
		ret = exec_command(list, fd_std);
		if (!list->next)
			break ;
		list = list->next;
	}
	return (ret);
}
