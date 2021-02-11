/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:21:44 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/11 14:28:32 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void			envp_handler(t_string *envp)
{
	if (!g_envp_size && !g_envp_times)
	{
		g_envp_size = 256;
		g_envp_times = 1;
	}
	g_envp = (t_string *)malloc(sizeof(t_string) * g_envp_size);
	while (envp[g_envp_count])
	{
		g_envp[g_envp_count] = ft_strdup(envp[g_envp_count]);
		g_envp_count++;
	}
	g_envp[g_envp_count] = NULL;
}

void			envp_double_size(void)
{
	t_string	*envp_copy;

	envp_copy = g_envp;
	g_envp_size = 256 * ++g_envp_times;
	g_envp = (t_string *)malloc(sizeof(t_string) * g_envp_size);
	g_envp_count = 0;
	while (envp_copy[g_envp_count])
	{
		g_envp[g_envp_count] = ft_strdup(envp_copy[g_envp_count]);
		g_envp_count++;
	}
	g_envp[g_envp_count] = NULL;
	libre_2d(envp_copy);
}

void			envp_reduce_size(void)
{
	t_string	*envp_copy;

	envp_copy = g_envp;
	if (g_envp_times - 1 > 0)
		--g_envp_times;
	g_envp_size = 256 * g_envp_times;
	g_envp = (t_string *)malloc(sizeof(t_string) * g_envp_size);
	g_envp_count = 0;
	while (envp_copy[g_envp_count])
	{
		g_envp[g_envp_count] = ft_strdup(envp_copy[g_envp_count]);
		g_envp_count++;
	}
	g_envp[g_envp_count] = NULL;
	libre_2d(envp_copy);
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
	free(g_envp[index]);
	while (index < g_envp_count)
	{
		g_envp[index] = g_envp[index + 1];
		index++;
	}
	--g_envp_count;
}
