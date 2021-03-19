/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:28:53 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/19 15:14:50 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

int				exit_shell(t_command *cmd)
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
			out("minishell: exit: ");
			out(cmd->args[1]);
			out(": numeric argument required\n");
			return (-1);
		}
		i++;
	}
	if (cmd->args[2] && cmd->args[1])
	{
		out("minishell: exit: too many arguments\n");
		out(cmd->args[0]);
		return (1);
	}
	return (-1);
}

int		cd()
{
	out("cd still need work \n");
	return (0);
}

int		pwd(void)
{
	char	buff[1024];

	if (getcwd(buff, sizeof(buff)) == NULL)
		return (-1);
	out(buff);
	out("\n");
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

int		env(void)
{
	t_map	*tmp;

	tmp = g_map;
	while (tmp)
	{
		if (tmp->value != NULL)
			printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	return (1);
}
