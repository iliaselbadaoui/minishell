/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:04:12 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/19 11:18:46 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

char		*ft_strcpy(char *dst, const char *src)
{
	int len;

	len = ft_strlen(src);
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (dst - len);
}

void		*ft_calloc(size_t count, size_t size)
{
	unsigned char			*ptr;
	int						len;
	int						i;

	len = count * size;
	i = 0;
	if (!(ptr = (unsigned char*)malloc(size * count)))
		return (NULL);
	while (i < len)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

void		free_2d_arr(char **arr)
{
	int i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	arr = NULL;
}

void			sort_env(void)
{
	t_string	swap;
	t_map		*next;
	t_map		*tmp;

	tmp = g_sorted_env;
	while (g_sorted_env)
	{
		next = g_sorted_env;
		while (next)
		{
			if (ft_strcmp(g_sorted_env->key, next->key) > 0)
			{
				swap = g_sorted_env->key;
				g_sorted_env->key = next->key;
				next->key = swap;
				swap = g_sorted_env->value;
				g_sorted_env->value = next->value;
				next->value = swap;
			}
			next = next->next;
		}
		g_sorted_env = g_sorted_env->next;
	}
	g_sorted_env = tmp;
}

void			clone_env(void)
{
	t_map	*node;
	t_map	*tmp;

	tmp = g_map;
	while (tmp)
	{
		node = init_map(tmp->key, tmp->value);
		add_to_map(&g_sorted_env, node);
		tmp = tmp->next;
	}
	sort_env();
}
