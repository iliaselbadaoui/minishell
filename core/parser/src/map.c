/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:52:49 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/18 20:53:17 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_map			*init_map(t_string key, t_string value)
{
	t_map		*node;

	node = (t_map *)malloc(sizeof(t_map));
	node->key = key;
	node->value = value;
	node->next = NULL;
	return (node);
}

void			add_to_map(t_map **head, t_map *node)
{
	t_map	*tmp;

	if (*head == NULL)
		*head = node;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	if (!g_map_fill_first_time)
		add_to_envp(node->key, node->value);
}

t_string		get_value_by_key(t_map *head, t_string key)
{
	while (head)
	{
		if (equals(head->key, key))
			return (head->value);
		head = head->next;
	}
	return (NULL);
}

void			free_by_key(t_map **head, t_string key)
{
	t_map	*tmp;
	t_map	*navigator;
	int		index;

	navigator = *head;
	index = 0;
	// printf("HERE\n");
	// if (equals(navigator->key, key))
	// {
	// 		tmp = navigator;
	// 		navigator = tmp->next;
	// 		free_map_node(tmp);
	// 		remove_and_resize(0);
	// 		return ;
	// }
	while (navigator)
	{
		if (equals(navigator->key, key))
		{
			tmp = navigator;
			navigator = tmp->next;
			free_map_node(tmp);
			break ;
		}
		index++;
		navigator = navigator->next;
	}
	remove_from_envp(index);;
}

void			free_map(t_map **head)
{
	t_map	*tmp;
	t_map	*navigator;

	navigator = *head;
	while (navigator)
	{
		tmp = navigator;
		navigator = navigator->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
}
