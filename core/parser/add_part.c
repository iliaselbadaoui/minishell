/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_part.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 00:14:36 by ielbadao          #+#    #+#             */
/*   Updated: 2020/07/02 11:19:33 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		add_part(t_part **head, t_part *part)
{
	if (*head == NULL)
	{
		*head = part;
	}
	else
	{
		while ((*head)->next)
			(*head) = (*head)->next;
		(*head)->next = part;
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
