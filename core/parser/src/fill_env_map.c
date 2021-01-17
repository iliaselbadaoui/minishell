/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 21:13:08 by ielbadao          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/01/18 00:18:16 by ielbadao         ###   ########.fr       */
=======
/*   Updated: 2021/01/06 10:30:32 by ielbadao         ###   ########.fr       */
>>>>>>> 828092d177da354b40d7381cbafff2f609711962
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
<<<<<<< HEAD
		t_string *env = ft_split_first(*envp, '=');
=======
		env = ft_split(*envp, '=');
>>>>>>> 828092d177da354b40d7381cbafff2f609711962
		add_to_map(&map, init_map(ft_strdup(env[0]), ft_strdup(env[1])));
		libre_2d(env);
		envp++;
	}
	return (map);
}
