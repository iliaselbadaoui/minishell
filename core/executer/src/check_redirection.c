
#include "../executer.h"

// Create all files
static int	init_files(t_redirect *tmp, t_bool is_append)
{
	int	fd;

	while (tmp->file_name)
	{
		// Check redirection type
		if (is_append)
			fd = open(tmp->file_name, O_RDWR|O_CREAT|O_APPEND, 0666);
		else
			fd = open(tmp->file_name, O_RDWR|O_CREAT, 0666);
		close(fd);
		tmp++;
	}
	return (fd);
}

void	check_redirection(t_command *list)
{
	t_redirect	*tmp;
	int			fd;

	tmp = list->redirections;
	if	(tmp->type == 'r')
	{
		fd = open(tmp->file_name, O_RDONLY, 0666);
		if (fd == -1){
			out("file not exist");
			return ;
		}
	}
	if (tmp->type == 'c')
		fd = init_files(tmp, false);
	else if (tmp->type == 'a')
		fd = init_files(tmp, true);
}
