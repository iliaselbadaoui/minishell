
#include "../executer.h"

void	print_struct(t_command *list)
{
	int i;
	while (list)
	{
		printf("\n__________________________\n");
		printf("\nID: [%d]\n", list->id);
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
		printf("\ntype: [%c]", list->redirections->type);
		printf("\nfd: [%d]", list->redirections->fd);
		printf("\nfile_name: [%s]", list->redirections->file_name);
		printf("\n__________________________\n");
		list = list->next;
	}
}
