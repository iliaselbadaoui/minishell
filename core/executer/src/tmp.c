/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:22:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/03 13:34:37 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

void	print_struct(t_command *list)
{
	int			i;
	int			j;
	t_redirect	*tmp;
	while (list)
	{
		i = list->id;
		while (list && list->id == i)
		{
			printf("ID:\t\t[%d]\n", list->id);
			printf("cmd:\t\t[%s]\n", list->args[0]);
			printf("args:\t\t");
			j = 1;
			while (list->args[j])
				printf("[%s]\t", list->args[j++]);
			tmp = list->redirections;
			while (tmp->file_name)
			{
				printf("\n\ntype:\t\t[%c]", tmp->type);
				printf("\nfd:\t\t[%d]", tmp->fd);
				printf("\nfile_name:\t[%s]", tmp->file_name);
				tmp++;
			}
			printf("\n\n***\n\n");
			list = list->next;
		}
		printf("\n--------------------\n\n");
	}
}
