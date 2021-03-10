/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:50:57 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/10 17:55:14 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

// static t_bool	is_valid(key)
// {

// 	return (true);
// }

// static t_bool		is_exist(key)
// {

// 	return (true);
// }

int		export(t_string *args)
{
	int			i;
	// int			j;
	// t_string	key;
	// t_string	value;
	// t_map		*tmp;

	i = 0;
	// int fd = open("tmp.txt", O_RDWR | O_CREAT);
	// if (!args[i+1])
	// 	put_env();
	while (args[++i])
	{
		out("[");
		out(args[i]);
		out("]\n");
		// j = -1;
		// while (args[i][++j] && args[i][j] != '='); // j is index of '='
		// key = substring(args[i], 0, j - 1);
		// value = substring(args[i], j + 1, ft_strlen(args[i]) - 1);
		// if (value)
		// 	out(value);
		// filter(value, 1);
		// Check Valid Key
		// if (!is_valid(key))
		// {
		// 	out("minishell: export: `");
		// 	out(args[i]);
		// 	out("': not a valid identifier");
		// }

		// Check if already Exist
		// if (is_exist(key)) // Update Data
		// {
		// 	tmp = g_map;
		// 	while (tmp)
		// 	{
		// 		if (equals(key, tmp->key))
		// 			tmp->value = value;
		// 		tmp = tmp->next;
		// 	}
		// }else{ // Insert Data

		// }
	}
	// close(fd);
	return (1);
}
