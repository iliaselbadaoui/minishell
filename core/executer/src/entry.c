/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:54:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/02/06 14:47:00 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

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

t_string	get_path(t_command *cmd)
{
	t_map		*tmp;
	char		**path;
	int			i;

	tmp = g_map;
	path = NULL;
	i = -1;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, "PATH"))
		{
			path = spliter(tmp->value, ':');
			break ;
		}
		tmp = tmp->next;
	}
	while (path && path[++i])
		// !ft_strcmp(cmd->args[0], path[i])
		if (ft_strchr(cmd->args[0], '/'))
			return(cmd->args[0]);
		else
		{
			return(ft_strjoin(ft_strjoin(path[i], "/"), cmd->args[0]));

		}
	return (NULL);
}

int		check_bins(t_command *cmd)
{
	t_string path;

	path = get_path(cmd);

	out(path);
	out("\n");
	return (1);
}

void	print_struct(t_command *list)
{
	int i;

	while (list)
	{
		printf("\n__________________________\n");
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
		printf("\n__________________________\n");
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
	if ((ret = check_builtins(cmd)))
		return (0);
	// Check bins
	if (check_bins(cmd))
		return (0);
	out("\nminishell$: Command not found: \n");
	exit(0);
	if (ret < 0)
		return (-1);
	return (0);
}

int		exec_cmds(t_command *list)
{
	int		ret;

	ret = 0;
	while (list)
	{
		ret = exec_cmd(list);
		if (ret == -1)
			break ;
		list = list->next;
	}
	// print_struct(list);
	return (ret);
}
