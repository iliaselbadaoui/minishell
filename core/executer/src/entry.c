/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:54:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/25 18:21:06 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

static t_command	*filter_all(t_command *list)
{
	t_command	*head;
	int			i;

	head = list;
	while (list)
	{
		i = -1;
		// Filter commands and args, ex: "ls" "-la" => ls -la
		while (list->args[++i])
			list->args[i] = filter(list->args[i]);
		list = list->next;
	}
	return head;
}

// Execute all commands, separated by ";"
// return 0, -1 : SUCCESS
// return 1, 127, 255, ... : FAILED
int	entry(t_command *list)
{
	int	ret;

	ret = 0;
	list = filter_all(list);
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
