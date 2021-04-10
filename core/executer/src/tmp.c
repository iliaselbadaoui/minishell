/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:22:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/04/10 17:37:39 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

void	print_struct(t_command *list)
{
	int	i;

	while (list)
	{
		printf("\n--------------------\n\n");
		printf("ID:\t\t[%d]\n", list->id);
		printf("cmd:\t\t[%s]\n", list->args[0]);
		printf("args:\t\t");
		i = 1;
		while (list->args[i])
			printf("[%s]\t", list->args[i++]);
		printf("\n\ntype:\t\t[%c]", list->redirections->type);
		printf("\nfd:\t\t[%d]", list->redirections->fd);
		printf("\nfile_name:\t[%s]\n\n", list->redirections->file_name);
		list = list->next;
	}
}
