/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:28:53 by mait-si-          #+#    #+#             */
/*   Updated: 2021/02/10 19:23:03 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

int				exit_shell(t_command *cmd)
{
	(void)cmd;
	// int	i;
	// int	is_number;

	// i = 0;
	// is_number = 0;
	// out("exit\n");

	// while (cmd->args[1][i])
	// 	if (! (is_number = ft_isdigit(cmd->args[1][i])))
	// 		break;
	// if (!is_number)
	// {
	// 	out("exit: ");
	// 	out(cmd->args[1]);
	// 	out(": numeric argument required\n");
	// 	return (-1);
	// }
	// if (cmd->args[2])
	// {
	// 	out("exit: too many arguments\n");
	// 	return (0);
	// }
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
	return (0);
}

int		export(void)
{
	out("export still need work \n");
	return (0);
}

int		unset()
{
	out("unset still need work \n");
	return (0);
}

int		env(void)
{
	t_map	*tmp;

	tmp = g_map;
	while (tmp)
	{
		out(tmp->key);
		out("=");
		out(tmp->value);
		out("\n");
		tmp = tmp->next;
	}
	return (0);
}
