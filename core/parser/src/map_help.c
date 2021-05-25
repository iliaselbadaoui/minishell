/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:43:49 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/25 17:36:43 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	free_map_node(t_map *tmp)
{
	free(tmp->key);
	tmp->key = NULL;
	free(tmp->value);
	tmp->value = NULL;
	free(tmp);
	tmp = NULL;
}

int	free_head(t_map **head, t_string key)
{
	t_map	*navigator;
	t_map	*tmp;

	navigator = *head;
	if (equals(navigator->key, key))
	{
		tmp = navigator;
		*head = tmp->next;
		free_map_node(tmp);
		remove_from_envp(0);
		return (1);
	}
	return (0);
}
