/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:28:53 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/19 16:12:39 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

int		exit_shell(t_command *cmd)
{
	int	i;
	int	is_number;

	i = 0;
	is_number = 0;
	out("exit\n");
	while (cmd->args[1] && cmd->args[1][i])
	{
		if (cmd->args[1][0] == '-' || cmd->args[1][0] == '+')
			i++;
		if (!(is_number = ft_isdigit(cmd->args[1][i])))
		{
			write(2, "minishell: exit: ", 17);
			write(2, cmd->args[1], length(cmd->args[1]));
			write(2, ": numeric argument required\n", 28);
			return (-1);
		}
		i++;
	}
	if (cmd->args[2] && cmd->args[1])
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		write(2, cmd->args[0], length(cmd->args[0]));
		return (1);
	}
	return (-1);
}

int		cd(t_string *args)
{
	(void)args;
	return (0);
}

int		pwd(int fd)
{
	char	buff[1024];

	if (getcwd(buff, sizeof(buff)) == NULL)
		return (-1);
	write(fd, &buff, length(buff));
	write(fd, "\n", 1);
	return (1);
}

int		unset(t_string *args)
{
	int			i;
	t_string	key;

	i = 0;
	while (args[++i])
	{
		key = filter(args[i]);
		if (is_valid_key(key))
		{
			if (get_value_by_key(g_map, key))
			{
				free_by_key(&g_sorted_env, key);
				free_by_key(&g_map, key);
			}
		}
		else
			printf("minishell: unset: `%s': not a valid identifier\n", key);
	}
	return (1);
}

int		env(int fd)
{
	t_map	*tmp;

	tmp = g_map;
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
	return (1);
}
