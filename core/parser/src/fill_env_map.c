/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 20:51:35 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/11 18:57:33 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_map			*fill_env(t_string *envp)
{
	t_map		*map;
	t_string	*env;

	map = NULL;
	envp_handler(envp);
	g_map_fill_first_time = 1;
	while (*envp)
	{
		env = ft_split_first(*envp, '=');
		add_to_map(&map, init_map(ft_strdup(env[0]), ft_strdup(env[1])));
		libre_2d(env);
		envp++;
	}
	g_map_fill_first_time = 0;
	return (map);
}
