/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:52:49 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/11 11:26:29 by ielbadao         ###   ########.fr       */
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
	{
		if (g_envp_count < g_envp_size - 1)
		{
			add_to_envp(node->key, node->value);
		}
		else
		{
			envp_double_size();
			add_to_envp(node->key, node->value);
		}
	}
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
	t_bool	found;
	int		index;

	navigator = *head;
	index = 0;
	found = false;
	while (navigator)
	{
		if (equals(navigator->next->key, key))
		{
			tmp = navigator->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			navigator->next = tmp->next;
			found = true;
		}
		index++;
		if (found)
			break ;
		navigator = navigator->next;
	}
	if ((g_envp_count - 1 > g_envp_size / 2 && g_envp_size > 256) ||
	(g_envp_count - 1 > g_envp_size && g_spliter_char == 256))
		remove_from_envp(index);
	else
	{
		envp_reduce_size();
		remove_from_envp(index);
	}
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
