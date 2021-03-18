/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:04:12 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/18 11:14:06 by 0x10000          ###   ########.fr       */
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

void			free_2d_arr(char **arr)
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
	t_map	*tmp;
	t_map	*before;
	t_map	*next;

	if (g_map)
	{
		tmp = g_map;
		before = 0;
		while (tmp->next)
		{
			next = tmp->next;
			if (tmp->key < next->key)
			{
				tmp->next = next->next;
				next->next = tmp;
				if (before)
					before->next = next;
				else
					g_map = next;
				tmp = g_map;
			}
			before = tmp;
			tmp = tmp->next;
		}
	}
}
