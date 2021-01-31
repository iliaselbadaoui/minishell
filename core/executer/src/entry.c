#include "../executer.h"

t_bool is_cmd(t_string cmd)
{
	if (!ft_strcmp(cmd, "echo") ||
		!ft_strcmp(cmd, "cd") ||
		!ft_strcmp(cmd, "pwd") ||
		!ft_strcmp(cmd, "export") ||
		!ft_strcmp(cmd, "unset") ||
		!ft_strcmp(cmd, "env") ||
		!ft_strcmp(cmd, "exit"))
		return (true);
	return (false);
}

// void print_struct(t_command *list)
// {
// 	while (list)
// 	{
// 		printf("\n__________________________\n");
// 		printf("\nID: [%d]\n", list->id);
// 		int i = 0;
// 		while (list->args[i])
// 			printf("[%s]\t", list->args[i++]);
// 		printf("\ntype: [%c]", list->redirections->type);
// 		printf("\nfd: [%d]", list->redirections->fd);
// 		printf("\nfile_name: [%s]", list->redirections->file_name);
// 		printf("\n__________________________\n");
// 		list = list->next;
// 	}
// }

int execute(t_command *list)
{
	if (!is_cmd(list->args[0]))
	{
		out("minishell: ");
		out(list->args[0]);
		out(": command not found\n");
		return (0);
	}
	// print_struct(list);
	return (1);
}
