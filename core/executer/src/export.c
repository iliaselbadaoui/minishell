/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:50:57 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/11 19:35:41 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

static t_bool	is_valid(t_string key)
{
	int i;

	i = 0;
	if (*key == '\0' || (!ft_isalpha(*key) && *key != '_'))
		return (false);
	while (key[++i])
		if (!ft_isalpha(key[i]) && !ft_isdigit(key[i]) && key[i] != '_')
			return (false);
	return (true);
}

static t_bool	is_exist(t_string key)
{
	t_map		*tmp;

	tmp = g_map;
	while (tmp)
	{
		if (equals(key, tmp->key))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void			put_env(void)
{
	t_map	*tmp;

	tmp = g_map;
	while (tmp)
	{
		printf("declare -x %s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

int				export(t_string *args)
{
	int i;
	int j;
	t_string key;
	t_string value;

	i = 0;
	if (!args[1])
	{
		put_env();
		return (0);
	}
	while (args[++i])
	{
		j = -1;
		while (args[i][++j] && args[i][j] != '=');
		key = substring(args[i], 0, j - 1);
		key = !key ? "" : filter(key);
		value = substring(args[i], j + 1, ft_strlen(args[i]) - 1);
		value = filter(value);

		// Check Valid Key
		if (!is_valid(key))
		{
			printf("minishell: export: `%s': not a valid identifier\n", args[i]);
			return (1);
		}

		// Check if already Exist
		if (is_exist(key)) // Update Data
		{
			printf("Exist\n");
		}else{ // Insert Data
			printf("New variable\n");
		}
		// free(key);
		// free(value);
	}
	return (1);
}
