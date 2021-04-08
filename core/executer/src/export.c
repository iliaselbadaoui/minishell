/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:50:57 by mait-si-          #+#    #+#             */
/*   Updated: 2021/04/08 14:32:47 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

// Update a given environment variable
static t_bool	update_key(t_map **env, t_string key, t_string value)
{
	t_map	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (equals(tmp->key, key))
		{
			if (value) // if there is a value insert it
			{
				if (tmp->value)
					free(tmp->value);
				tmp->value = ft_strdup(value);
			}
			return (true);
		}
		tmp = tmp->next;
	}
	return (false);
}

// Print out all envirement variables by order (g_sorted_env)
static int		put_env(int fd)
{
	t_map	*tmp;

	tmp = g_sorted_env;
	while (tmp)
	{
		if (tmp->value == NULL)
		{
			write(fd, "declare -x ", 11);
			write(fd, tmp->key, length(tmp->key));
			write(fd, "\n", 1);
		}
		else
		{
			write(fd, "declare -x ", 11);
			write(fd, tmp->key, length(tmp->key));
			write(fd, "=\"", 2);
			write(fd, tmp->value, length(tmp->value));
			write(fd, "\"\n", 2);
		}
		tmp = tmp->next;
	}
	return (0); // SUCCESS
}

// Update key if exist, if not add it to g_map && g_sorted_env
void		update_env(t_string key, t_string value)
{
	if (update_key(&g_map, key, value) && update_key(&g_sorted_env, key, value))
		return ;
	add_to_map(&g_map, init_map(key, value));
	add_to_map(&g_sorted_env, init_map(key, value));
}

// Extract key and value from passed argument
static int		set_data(t_string args, t_string *key, t_string *value)
{
	int		j;

	j = 0;
	while (args[j] && args[j] != '=')
		j++;
	*key = substring(args, 0, j - 1);
	*key = !*key ? ft_strdup("") : filter(*key);
	if (args[j] == '=')
	{
		*value = substring(args, j + 1, ft_strlen(args) - 1);
		*value = !*value ? ft_strdup("") : filter(*value);
	}
	else
		*value = NULL;
	if (!is_valid_key(*key))
	{
		if (!*value)
			printf("minishell: export: `%s': not a valid identifier\n", *key);
		else
			printf("minishell: export: `%s=%s': not a valid identifier\n", *key, *value);
		return (1); // FAILED
	}
	return (0); // SUCCESS
}

// Export Command entry
int				export(t_string *args, int fd)
{
	int			i;
	int			ret;
	t_string	key;
	t_string	value;

	i = 0;
	ret = 0;
	if (!args[1])
		return (put_env(fd));
	while (args[++i])
	{
		// Set Key & Value from args[i]
		if (set_data(args[i], &key, &value)) // if it Failed
		{
			ret++;
			free(key);
			if (value)
				free(value);
			continue ;
		}
		// ADD/Update Key & Value
		update_env(key, value);
		// if (key)
		// 	free(key);
		// if (value)
		// 	free(value);
	}
	sort_env();
	return (ret ? 1 : 0); // 0: SUCCESS, 1: FAILED to add/update key/keys
}
