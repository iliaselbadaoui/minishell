/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:28:53 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/07 20:53:12 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

static void	free_env(t_string key)
{
	if (key_exist(g_sorted_env, key))
	{
		free_by_key(&g_sorted_env, key);
		free_by_key(&g_map, key);
	}
}

// Print out current path to a file descriptor
int	pwd(int fd)
{
	char	buff[1024];

	if (getcwd(buff, sizeof(buff)) == NULL)
		return (EXIT_FAILURE); // Failed
	write(fd, &buff, length(buff));
	write(fd, "\n", 1);
	return (EXIT_SUCCESS); // SUCCESS
}

// Remove a key/keys from environment variables
int	unset(t_string *args)
{
	int			i;
	int			ret;
	t_string	key;

	i = 0;
	ret = 0;
	while (args[++i])
	{
		key = filter(ft_strdup(args[i]));
		if (is_valid_key(key))
			free_env(key);
		else
		{
			printf("minishell: unset: `%s': not a valid identifier\n", key);
			ret++;
		}
		free(key);
	}
	if (ret)
		return (EXIT_FAILURE); // FAILED invalid key/keys
	return (EXIT_SUCCESS); // SUCCESS
}

// Print out all environment variables to a file descriptor
int	env(int fd)
{
	t_map	*tmp;

	tmp = g_map;
	if (tmp == NULL)
		return (EXIT_FAILURE); // FAILED
	while (tmp)
	{
		if (tmp->value != NULL)
		{
			write(fd, tmp->key, length(tmp->key));
			write(fd, "=", 1);
			write(fd, tmp->value, length(tmp->value));
			write(fd, "\n", 1);
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS); // SUCCESS
}
