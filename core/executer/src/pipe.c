/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:48:58 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/18 23:49:25 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

typedef struct	s_data
{
	int				id;
	struct s_data	*next;
}				t_data;

static void	test(t_command *list, t_data **data)
{
	(*data)->id = 1;
	while (list->next && list->next->id == id)
	{

	}
	// first cmd
	if (list->next)
	{

	}
	// middle cmd
	else if ()
	{

	}
	// last cmd
	else
	{

	}

	return (data);
}

int	handle_pipes(t_command **list)
{
	int			id;
	pid_t		pid;
	int			fd[2];
	int			input;
	t_data		*data;

	id = (*list)->id;
	test(*list, &data);
	// Loop through pipe line (separated by | )
	while ((*list)->next && (*list)->next->id == id)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			// CHILD PROCESS.

		}
		// PARENT PROCESS

		(*list) = (*list)->next;
	}
	return (0);
}
