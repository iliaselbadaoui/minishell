/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:54:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/18 23:13:58 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

// Execute all commands, separated by ";"
// return 0, -1 : SUCCESS
// return 1, 127, 255, ... : FAILED
int	exec_cmds(t_command *list)
{
	int	ret;
	int	fd_std[2];

	ret = 0;
	fd_std[0] = dup(0);
	fd_std[1] = dup(1);
	// Loop through commands line (separated by ; )
	while (list)
	{
		// Check pipes
		if (list->next && list->id == list->next->id)
			ret = handle_pipes(&list);
		else
			ret = exec_command(list, fd_std);
		list = list->next;
	}
	return (ret);
}
