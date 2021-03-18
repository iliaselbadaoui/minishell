/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:50:57 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/18 11:48:24 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

t_bool	is_valid_key(t_string key)
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

static int		put_env(void)
{
	t_map	*tmp;

	// sort_env();
	tmp = g_map;
	while (tmp)
	{
		if (tmp->value == NULL)
			printf("declare -x %s\n", tmp->key);
		else
			printf("declare -x %s=\"%s\"\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	return (1);
}

static void		update_key(t_string key, t_string value)
{
	t_map	*tmp;

	tmp = g_map;
	while (tmp)
	{
		if (equals(tmp->key, key))
		{
			if (value != NULL)
				tmp->value = value;
			return ;
		}
		tmp = tmp->next;
	}
	add_to_map(&g_map, init_map(key, value));
}

static int		set_data(t_string args, t_string *key, t_string *value)
{
	int		j;

	j = -1;
	while (args[++j] && args[j] != '=');
	*key = substring(args, 0, j - 1);
	*key = !*key ? "" : filter(*key);
	if (args[j] == '=')
	{
		*value = substring(args, j + 1, ft_strlen(args) - 1);
		*value = !*value ? "" : filter(*value);
	}
	else
		*value = NULL;
	if (!is_valid_key(*key))
	{
		printf("minishell: export: `%s=%s': not a valid identifier\n", *key, *value);
		free(key);
		if (!value)
			free(value);
		return (1);
	}
	return (0);
}

int				export(t_string *args)
{
	int i;
	int ret;
	t_string key;
	t_string value;

	i = 0;
	if (!args[1])
		return (put_env());
	while (args[++i])
	{
		if ((ret = set_data(args[i], &key, &value)) == 1)
			continue ;
		update_key(key, value);
		// free(key);
		// free(value);
	}
	return (1);
}