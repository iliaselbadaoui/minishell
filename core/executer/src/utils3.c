#include "../executer.h"

void	update_env(t_map **head, t_string key, t_string value)
{
	t_map *tmp;

	tmp = *head;
	while (tmp)
	{
		if (equals(key, tmp->key))
		{
			tmp->value = value;
			return ;
		}
		tmp = tmp->next;
	}
}
