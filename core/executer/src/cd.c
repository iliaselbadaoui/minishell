/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:35:17 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/23 00:39:50 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

// get path by ~, ~username or -
static t_string	get_path(t_string arg)
{
	t_string	path;

	path = filter(ft_strdup(arg));
	if (equals(path, "-"))
	{
		free(path);
		path = ft_strdup(get_env_value("OLDPWD"));
	}
	else if (equals(path, "~"))
	{
		free(path);
		path = ft_strdup(get_env_value("HOME"));
	}
	else if (*path == '~' && equals((path + 1), get_env_value("USER")))
	{
		free(path);
		path = ft_strdup(get_env_value("HOME"));
	}
	return (path);
}

// Go to Home Directory if the argument not set
static int	to_home(void)
{
	t_string	path;

	path = get_value_by_key(g_container->map, "HOME");
	if (!path)
	{
		write(2, "minishell: cd: HOME not set\n", 28);
		return (EXIT_FAILURE); // FAILED
	}
	if (*path == '\0')
		path = getcwd(NULL, 1024);
	else
		path = ft_strdup(path);
	if (chdir(path) == -1)
		return (no_file(path)); // FAILED
	update_env("OLDPWD", get_env_value("PWD"));
	update_env("PWD", path);
	free(path);
	return (EXIT_SUCCESS); // SUCCESS
}

// Main CD function
int	cd(t_string *args)
{
	t_string	path;

	// Only cd
	if (!args[1])
		return (to_home());
	// cd with argument, ex: cd /tmp
	path = get_path(args[1]);
	if (chdir(path) == -1)
		return (no_file(path)); // FAILED
	free(path);
	path = getcwd(NULL, 1024); // Get current path
	update_env("OLDPWD", get_env_value("PWD"));
	update_env("PWD", path);
	free(path);
	return (EXIT_SUCCESS); //SUCCESS
}
