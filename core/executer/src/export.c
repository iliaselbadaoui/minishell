/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:50:57 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/25 18:14:43 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

// Update a given environment variable
static t_bool	update_key(t_map *env, t_string key, t_string value)
{
	t_map	*tmp;

	tmp = env;
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

// Print out all envirement variables by order (g_container->sorted_env)
static int	put_env(void)
{
	t_map	*tmp;

	tmp = g_container->sorted_env;
	while (tmp)
	{
		if (tmp->value == NULL)
		{
			write(1, "declare -x ", 11);
			write(1, tmp->key, length(tmp->key));
			write(1, "\n", 1);
		}
		else
		{
			write(1, "declare -x ", 11);
			write(1, tmp->key, length(tmp->key));
			write(1, "=\"", 2);
			write(1, tmp->value, length(tmp->value));
			write(1, "\"\n", 2);
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS); // SUCCESS
}

// Update key if exist, if not add it to g_container->map && g_container->sorted_env
void	update_env(t_string key, t_string value)
{
	if (update_key(g_container->map, key, value) && update_key(g_container->sorted_env, key, value))
		return ;
	// if (value)
	// 	value = ft_strdup(value);
	add_to_map(&g_container->map, init_map(ft_strdup(key), ft_strdup(value)));
	add_to_map(&g_container->sorted_env, init_map(ft_strdup(key), ft_strdup(value)));
}

// Extract key and value from passed argument
static int	set_data(t_string args, t_string *key, t_string *value)
{
	int	j;

	j = 0;
	while (args[j] && args[j] != '=')
		j++;
	*key = substring(args, 0, j - 1);
	if (!*key)
		*key = ft_strdup("");
	if (args[j] == '=')
	{
		*value = substring(args, j + 1, ft_strlen(args) - 1);
		if (!*value)
			*value = ft_strdup("");
	}
	else
		*value = NULL;
	if (!is_valid_key(*key))
		return (not_valid(*key, *value));
	return (EXIT_SUCCESS); // SUCCESS
}

// Main Export function
int	export(t_string *args)
{
	int			i;
	int			ret;
	t_string	key;
	t_string	value;

	i = 0;
	ret = 0;
	if (!args[1])
		return (put_env());
	while (args[++i])
	{
		// Set Key & Value from args[i]
		if (set_data(args[i], &key, &value)) // if it Failed
		{
			ret++;
			continue ;
		}
		// ADD/Update Key & Value
		update_env(key, value);
		free(key);
		if (value)
			free(value);
	}
	sort_env();
	if (ret)
		return (EXIT_FAILURE); // FAILED to add/update key/keys
	return (EXIT_SUCCESS); // SUCCESS
}
