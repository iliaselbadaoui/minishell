/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_part.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 00:14:36 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/08 11:36:43 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		add_part(t_part **head, t_part *part)
{
	t_part	*tmp;

	if (*head == NULL)
	{
		*head = part;
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = part;
	}
}

void		free_double_char_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
