/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:21:44 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/28 20:41:26 by ielbadao         ###   ########.fr       */
/*   Updated: 2021/05/28 20:33:08 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	envp_handler(t_string *envp)
{
	g_container->envp = (t_string *)malloc(sizeof(t_string) * 4096);
	g_container->envp_shadow = (t_string *)malloc(sizeof(t_string) * 4096);
	while (envp[g_container->envp_count])
	{
		g_container->envp[g_container->envp_count]
			= ft_strdup(envp[g_container->envp_count]);
		g_container->envp_count++;
	}
	g_container->envp[g_container->envp_count] = NULL;
}

void	add_to_envp(t_string key, t_string value)
{
	t_string	joined;

	joined = ft_strjoin(key, "=");
	g_container->envp[g_container->envp_count++] = ft_strjoin(joined, value);
	g_container->envp[g_container->envp_count] = NULL;
	free(joined);
}

static void	remove_help(int i)
{
	free(g_container->envp[i]);
	g_container->envp[i] = NULL;
	while (i < g_container->envp_count)
	{
		g_container->envp[i] = g_container->envp[i + 1];
		i++;
	}
}

void	remove_from_envp(int index)
{
	int			j;

	j = 0;
	if (g_container->envp_count > 0)
		--g_container->envp_count;
	while (g_container->envp[j])
	{
		if (j == index)
			remove_help(j);
		if (!g_container->envp[j])
			break ;
		j++;
	}
}
