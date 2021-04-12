/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:22:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/04/12 13:14:19 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

void	print_struct(t_command *list)
{
	int			i;
	t_redirect	*tmp;

	while (list)
	{
		printf("\n--------------------\n\n");
		printf("ID:\t\t[%d]\n", list->id);
		printf("cmd:\t\t[%s]\n", list->args[0]);
		printf("args:\t\t");
		i = 1;
		while (list->args[i])
			printf("[%s]\t", list->args[i++]);
		tmp = list->redirections;
		while (tmp->file_name)
		{
			printf("\n\ntype:\t\t[%c]", tmp->type);
			printf("\nfd:\t\t[%d]", tmp->fd);
			printf("\nfile_name:\t[%s]", tmp->file_name);
			tmp++;
		}
		printf("\nfile_name:\t[%s]", tmp->file_name);
		list = list->next;
	}
}
