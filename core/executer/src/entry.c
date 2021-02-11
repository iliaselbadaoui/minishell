/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:54:14 by mait-si-          #+#    #+#             */
/*   Updated: 2021/02/10 19:25:24 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"



// void	print_struct(t_command *list)
// {
// 	int i;
// 	while (list)
// 	{
// 		printf("\n__________________________\n");
		// printf("\nID: [%d]\n", list->id);
		// out("cmd:\t");
		// out(list->args[0]);
		// out("\nargs:\t");
		// i = 1;
		// while (list->args[i])
		// {
		// 	out(list->args[i++]);
		// 	out("   ");
		// }
		// out("\n");
		// printf("\ntype: [%c]", list->redirections->type);
		// printf("\nfd: [%d]", list->redirections->fd);
		// printf("\nfile_name: [%s]", list->redirections->file_name);
// 		printf("\n__________________________\n");
// 		list = list->next;
// 	}
// }

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
	// Check builtins functions and bins
	if (!(ret = check_builtins(cmd)))
		return (0);
	if (ret == -1)
		return (-1);
	if (check_bins(cmd))
		return (0);

	out("minishell$: ");
	out(cmd->args[0]);
	out(": command not found\n");
	return (CMMAND_NOT_FOUND);
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
