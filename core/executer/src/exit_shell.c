/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:08:46 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/28 16:51:19 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

static int	failed_exit(t_string str)
{
	write(2, "minishell: exit: ", 17);
	write(2, str, length(str));
	write(2, ": numeric argument required\n", 28);
	return (255);
}

// Exit minishell
int	exit_shell(t_command *cmd)
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
		is_number = ft_isdigit(cmd->args[1][i]);
		if (!is_number)
			return (failed_exit(cmd->args[1]));
		i++;
	}
	if (cmd->args[2] && cmd->args[1])
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		return (EXIT_FAILURE);
	}
	return (-1);
}
