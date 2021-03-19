/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:50:57 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/19 15:47:57 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

t_bool			is_valid_key(t_string key)
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
	return (1);
}

static void		update_key(t_string key, t_string value)
{
	t_map	*tmp1;
	t_map	*tmp2;
	t_bool	did_update;

	tmp1 = g_map;
	tmp2 = g_sorted_env;
	did_update = false;
	while (tmp1)
	{
		if (equals(tmp1->key, key))
		{
			if (value)
				tmp1->value = value;
			did_update = true;
			break ;
		}
		tmp1 = tmp1->next;
	}
	while (tmp2)
	{
		if (equals(tmp2->key, key))
		{
			if (value)
				tmp2->value = value;
			did_update = true;
			break ;
		}
		tmp2 = tmp2->next;
	}
	if (did_update)
		return ;
	add_to_map(&g_map, init_map(key, value));
	add_to_map(&g_sorted_env, init_map(key, value));
}

static int		set_data(t_string args, t_string *key, t_string *value)
{
	int		j;

	j = 0;
	while (args[j] && args[j] != '=')
		j++;
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
		if (!*value)
			printf("minishell: export: `%s': not a valid identifier\n", *key);
		else
			printf("minishell: export: `%s=%s': not a valid identifier\n", *key, *value);
		return (1);
	}
	return (0);
}

int				export(t_string *args, int fd)
{
	int			i;
	int			ret;
	t_string	key;
	t_string	value;

	i = 0;
	if (!args[1])
		return (put_env(fd));
	while (args[++i])
	{
		if ((ret = set_data(args[i], &key, &value)) == 1)
			continue ;
		update_key(key, value);
	}
	sort_env();
	return (1);
}
