#include "../executer.h"

// is the key valid or not, ex: _KEY_test2 is valid, 2KEY_-_test is not valid
t_bool			is_valid_key(t_string key)
{
	int i;

	i = 0;
	if (*key == '\0' || (!ft_isalpha(*key) && *key != '_'))
		return (false);
	while (key[++i])
		if (!ft_isalpha(key[i]) && !ft_isdigit(key[i]) && key[i] != '_')
			return (false);
	return (true);
}

t_bool		key_exist(t_map *head, t_string key)
{
	while (head)
	{
		if (equals(head->key, key))
			return (true);
		head = head->next;
	}
	return (false);
}

int			no_file(t_string path)
{
	write(2, "minishell: cd: ", 15);
	write(2, path, length(path));
	write(2, ": No such file or directory\n", 28);
	free(path);
	return (1);
}
