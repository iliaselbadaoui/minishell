/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:28:53 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/23 20:16:39 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

static void	free_env(t_string key)
{
	if (key_exist(g_container->sorted_env, key))
	{
		free_by_key(&g_container->sorted_env, key);
		free_by_key(&g_container->map, key);
	}
}

// Print out current path to a file descriptor
int	pwd(void)
{
	char	buff[1024];

	if (getcwd(buff, sizeof(buff)) == NULL)
		return (EXIT_FAILURE); // Failed
	write(1, &buff, length(buff));
	write(1, "\n", 1);
	return (EXIT_SUCCESS); // SUCCESS
}

// Remove a key/keys from environment variables
int	unset(t_string *args)
{
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	while (args[++i])
	{
		if (is_valid_key(args[i]))
			free_env(args[i]);
		else
		{
			printf("minishell: unset: `%s': not a valid identifier\n", args[i]);
			ret++;
		}
	}
	if (ret)
		return (EXIT_FAILURE); // FAILED invalid key/keys
	return (EXIT_SUCCESS); // SUCCESS
}

// Print out all environment variables to a file descriptor
int	env(void)
{
	t_map	*tmp;

	tmp = g_container->map;
	if (tmp == NULL)
		return (EXIT_FAILURE); // FAILED
	while (tmp)
	{
		if (tmp->value != NULL)
		{
			write(1, tmp->key, length(tmp->key));
			write(1, "=", 1);
			write(1, tmp->value, length(tmp->value));
			write(1, "\n", 1);
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS); // SUCCESS
}
