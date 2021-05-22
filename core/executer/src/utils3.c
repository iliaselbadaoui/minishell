/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:18:57 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/22 15:17:31 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

// is the key valid or not, ex: _KEY_test2 is valid, 2KEY_-_test is not valid
t_bool	is_valid_key(t_string key)
{
	int	i;

	i = 0;
	if (*key == '\0' || (!ft_isalpha(*key) && *key != '_'))
		return (false);
	while (key[++i])
		if (!ft_isalpha(key[i]) && !ft_isdigit(key[i]) && key[i] != '_')
			return (false);
	return (true);
}

// Is a given key is exit on environment variables
t_bool	key_exist(t_map *head, t_string key)
{
	while (head)
	{
		if (equals(head->key, key))
			return (true);
		head = head->next;
	}
	return (false);
}

// No such file or directory on that path
int	no_file(t_string path)
{
	write(2, "minishell: cd: ", 15);
	write(2, path, length(path));
	write(2, ": No such file or directory\n", 28);
	free(path);
	return (1);
}

// Export, not a valid identifier
int	not_valid(t_string key, t_string value)
{
	if (!value)
		printf("minishell: export: `%s': not a valid identifier\n", key);
	else
		printf("minishell: export: `%s=%s': not a valid identifier\n", key, value);
	free(key);
	if (value)
		free(value);
	return (EXIT_FAILURE); // FAILED
}
