
#include "../executer.h"

int	check_redirection(t_command *list)
{
	t_redirect	*tmp;
	int			fd1;
	// int			fd2;

	tmp = list->redirections;
	while (tmp->file_name)
	{
		if (tmp->type == 'c')		// >
			fd1 = open(tmp->file_name, O_RDWR|O_CREAT|O_TRUNC, 0666);
		else if (tmp->type == 'a')	// >>
			fd1 = open(tmp->file_name, O_RDWR|O_CREAT|O_APPEND, 0666);
		// else if (tmp->type == 'r')	// <
		// {
		// 	fd2 = open(tmp->file_name, O_RDONLY, 0666);
		// 	if (fd2 == -1)
		// 		break ;
		// }
		tmp++;
		if (tmp->file_name)
			close(fd1);
	}
	dup2(fd1, 1);
	return (fd1);
}
