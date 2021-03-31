/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:28:53 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/31 12:21:12 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

// Exit minishell
int		exit_shell(t_command *cmd)
{
	int	i;
	int	is_number;

	i = 0;
	is_number = 0;
	write(1, "exit\n", 5);
	while (cmd->args[1] && cmd->args[1][i])
	{
		if (cmd->args[1][0] == '-' || cmd->args[1][0] == '+')
			i++;
		if (!(is_number = ft_isdigit(cmd->args[1][i])))
		{
			write(2, "minishell: exit: ", 17);
			write(2, cmd->args[1], length(cmd->args[1]));
			write(2, ": numeric argument required\n", 28);
			return (255); // FAILED (exit)
		}
		i++;
	}
	if (cmd->args[2] && cmd->args[1])
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		write(2, cmd->args[0], length(cmd->args[0]));
		return (1); // didn't exit
	}
	return (-1); // SUCCESS exit
}

// Change directory
int		cd(t_string *args)
{
	t_string str;

	if (args[1])
	{
		str = filter(ft_strdup(args[1]));
		if (chdir(str) == -1)
		{
			write(2, "minishell: cd: ", 15);
			write(2, str, length(str));
			write(2, ": No such file or directory\n", 28);
			free(str);
			return (1); // FAILED
		}
		update_env("OLDPWD", get_env_value("PWD"));
		update_env("PWD", str);
		free(str);
	}
	else
	{
		if (chdir(get_value_by_key(g_map, "HOME")) == -1)
		{
			write(2, "minishell: cd: HOME not set\n", 28);
			return (1); // FAILED
		}
		update_env("OLDPWD", get_env_value("PWD"));
		update_env("PWD", get_env_value("HOME"));
	}
	return (0); //SUCCESS
}

// Print out current path to a file descriptor
int		pwd(int fd)
{
	char	buff[1024];

	if (getcwd(buff, sizeof(buff)) == NULL)
		return (1); // Failed
	write(fd, &buff, length(buff));
	write(fd, "\n", 1);
	return (0); // SUCCESS
}

// Remove a key/keys from environment variables
int		unset(t_string *args)
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
		{
			if (key_exist(g_sorted_env, key))
			{
				free_by_key(&g_sorted_env, key);
				free_by_key(&g_map, key);
			}
		}
		else
		{
			printf("minishell: unset: `%s': not a valid identifier\n", key);
			ret++;
		}
		free(key);
	}
	return (ret ? 1 : 0); // 0: SUCCESS, 1: FAILED invalid key/keys
}

// Print out all environment variables to a file descriptor
int		env(int fd)
{
	t_map	*tmp;

	tmp = g_map;
	if (tmp == NULL)
		return (1); // FAILED
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
	return (0); // SUCCESS
}
