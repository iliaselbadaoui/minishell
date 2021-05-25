/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:21:44 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/25 16:35:16 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	envp_handler(t_string *envp)
{
	g_container->envp = (t_string *)malloc(sizeof(t_string) * 4096);
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
	g_container->envp[g_container->envp_count] = ft_strjoin(joined, value);
	g_container->envp[++g_container->envp_count] = NULL;
	free(joined);
}

void	remove_from_envp(int index)
{
	t_string	*new_envp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	new_envp = (t_string *)malloc(sizeof(t_string) * 4096);
	if (g_container->envp_count > 0)
		--g_container->envp_count;
	while (g_container->envp[j])
	{
		if (j == index)
			j++;
		if (g_container->envp[j])
			new_envp[i] = ft_strdup(g_container->envp[j]);
		else
			break ;
		i++;
		j++;
	}
	new_envp[i] = NULL;
	libre_2d(g_container->envp);
	g_container->envp = new_envp;
}
