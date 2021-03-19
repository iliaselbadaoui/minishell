/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:21:44 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/19 10:32:20 by ielbadao         ###   ########.fr       */
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
	t_string	*new_envp;
	int			i;
	int			j;

	i = j = 0;
	new_envp = (t_string *)malloc(sizeof(t_string) * 4096);
	if (g_envp_count > 0)
		--g_envp_count;
	while (g_envp[j])
	{
		if (j == index)
			j++;
		if (g_envp[j])
			new_envp[i] = ft_strdup(g_envp[j]);
		else
			break ;
		i++;
		j++;
	}
	new_envp[i] = NULL;
	libre_2d(g_envp);
	printf("HEY %d\n", index);
	g_envp = new_envp;
}
