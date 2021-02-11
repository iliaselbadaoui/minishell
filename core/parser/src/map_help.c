/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:43:49 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/11 14:54:05 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void				remove_and_resize(int index)
{
	if ((g_envp_count - 1 > g_envp_size / 2 && g_envp_size > 256) ||
	(g_envp_count - 1 > g_envp_size && g_spliter_char == 256))
		remove_from_envp(index);
	else
	{
		envp_reduce_size();
		remove_from_envp(index);
	}
}
