/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:48:54 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/08 11:53:56 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		free_parts(t_part *head)
{
	t_part		*tmp;

	while (head)
	{
		tmp = head;
		free(tmp->command);
		free_double_char_arr(tmp->args);
		free(tmp);
		head = head->next;
	}
}
