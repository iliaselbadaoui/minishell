/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 20:51:35 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/26 17:07:33 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_map	*fill_env(t_string *envp)
{
	t_map		*map;
	t_string	*env;
	t_string	key;
	t_string	value;

	map = NULL;
	envp_handler(envp);
	g_container->map_fill_first_time = 1;
	while (*envp)
	{
		env = ft_split_first(*envp, '=');
		key = ft_strdup(env[0]);
		value = ft_strdup(env[1]);
		add_to_map(&map, init_map(key, value));
		libre_2d(env);
		envp++;
	}
	g_container->map_fill_first_time = 0;
	return (map);
}
