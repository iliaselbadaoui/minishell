/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:22:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/04/01 19:34:36 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

void	print_struct(t_command *list)
{
	int i;
	while (list)
	{
		printf("\n__________________________\n");
		printf("ID:\t\t[%d]\n", list->id);
		printf("cmd:\t\t[%s]\n", list->args[0]);
		printf("args:\t\t");
		i = 1;
		while (list->args[i])
			printf("[%s]\t", list->args[i++]);
		printf("\n\ntype:\t\t[%c]", list->redirections->type);
		printf("\nfd:\t\t[%d]", list->redirections->fd);
		printf("\nfile_name:\t[%s]\n", list->redirections->file_name);
		list = list->next;
	}
}
