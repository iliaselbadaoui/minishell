/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:21:44 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/18 21:40:36 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void			envp_handler(t_string *envp)
{
	g_envp = (t_string *)malloc(sizeof(t_string) * 4096);
	while (envp[g_envp_count])
	{
		g_envp[g_envp_count] = ft_strdup(envp[g_envp_count]);
		g_envp_count++;
	}
	g_envp[g_envp_count] = NULL;
}

void			add_to_envp(t_string key, t_string value)
{
	t_string	joined;

	joined = ft_strjoin(key, "=");
	g_envp[g_envp_count] = ft_strjoin(joined, value);
	g_envp[++g_envp_count] = NULL;
	free(joined);
}

void			remove_from_envp(int index)
{
	t_string	tmp;

	tmp = g_envp[index];
	while (g_envp[index])
	{
		g_envp[index] = g_envp[index + 1];
		index++;
	}
	if (g_envp_count > 0)
		--g_envp_count;
	free(tmp);
}
