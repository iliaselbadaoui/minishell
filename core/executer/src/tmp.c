/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:22:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/10 14:22:17 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

void	print_struct(t_command *list)
{
	int i;
	while (list)
	{
		printf("\n__________________________\n");
		printf("\nID: [%d]\n", list->id);
		out("cmd:\t");
		out(list->args[0]);
		out("\nargs:\t");
		i = 1;
		while (list->args[i])
		{
			out("[");
			out(list->args[i++]);
			out("]   ");
		}
		out("\n");
		printf("\ntype: [%c]", list->redirections->type);
		printf("\nfd: [%d]", list->redirections->fd);
		printf("\nfile_name: [%s]", list->redirections->file_name);
		printf("\n__________________________\n");
		list = list->next;
	}
}
