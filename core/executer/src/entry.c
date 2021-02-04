/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:54:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/02/04 19:03:42 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

int		cd()
{
	out("cd \n");
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

int		export()
{
	out("export \n");
	return (0);
}

int		unset()
{
	out("unset \n");
	return (0);
}

int		env(void)
{
	out("env \n");
	return (0);
}

int		check_builtins(t_command *cmd)
{
	if (!ft_strcmp(cmd->args[0], "exit"))
		return (-1);
	else if (!ft_strcmp(cmd->args[0], "echo"))
		return (echo(cmd->args));
	else if (!ft_strcmp(cmd->args[0], "cd"))
		return (cd());
	else if (!ft_strcmp(cmd->args[0], "pwd"))
		return (pwd());
	else if (!ft_strcmp(cmd->args[0], "export"))
		return (export());
	else if (!ft_strcmp(cmd->args[0], "unset"))
		return (unset());
	else if (!ft_strcmp(cmd->args[0], "env"))
		return (env());
	return (0);
}

void	print_struct(t_command *list)
{
	int i;

	while (list)
	{
		// printf("\n__________________________\n");
		// printf("\nID: [%d]\n", list->id);
		out("cmd:\t");
		out(list->args[0]);
		out("\nargs:\t");
		i = 1;
		while (list->args[i])
		{
			out(list->args[i++]);
			out("   ");
		}
		out("\n");
		// printf("\ntype: [%c]", list->redirections->type);
		// printf("\nfd: [%d]", list->redirections->fd);
		// printf("\nfile_name: [%s]", list->redirections->file_name);
		// printf("\n__________________________\n");
		list = list->next;
	}
}
void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		out("\nminishell$ ");
		signal(SIGINT, signal_handler);
	}
}
int	exec_cmd(t_command *cmd)
{
	int	ret;

	ret = 0;
	// Check builtins
	if ((ret = check_builtins(cmd)) == 0)
		return (ret);
	// Check bins
	return (0);
}

int		exec_cmds(t_command *list)
{
	int		ret;
	// int		i;

	// i = 0;
	ret = 0;
	// while (list)
	// {
		ret = exec_cmd(list);
	// 	if (ret == -1)
	// 		break ;
	// 	list++;
	// }
	// print_struct(list);
	return (ret);
}
