/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 20:51:35 by ielbadao          #+#    #+#             */
/*   Updated: 2021/01/29 20:52:31 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../parser.h"

t_map			*fill_env(t_string *envp)
{
	t_map		*map;
	t_string	*env;

	map = NULL;
	while (*envp)
	{
		env = ft_split_first(*envp, '=');
		add_to_map(&map, init_map(ft_strdup(env[0]), ft_strdup(env[1])));
		libre_2d(env);
		envp++;
	}
	return (map);
}
