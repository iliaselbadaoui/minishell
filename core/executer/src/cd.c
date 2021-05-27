/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:35:17 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/27 19:19:13 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

// get path by ~, ~username or -
static t_string	get_path(t_string arg)
{
	if (equals(arg, "-"))
		return (get_env_value("OLDPWD"));
	else if (equals(arg, "~"))
		return (get_env_value("HOME"));
	else if (*arg == '~' && equals((arg + 1), get_env_value("USER")))
		return (get_env_value("HOME"));
	return (arg);
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
	update_env(ft_strdup("OLDPWD"), ft_strdup(get_env_value("PWD")));
	update_env(ft_strdup("PWD"), path);
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
		return (no_file(ft_strdup(path))); // FAILED
	path = getcwd(NULL, 1024); // Get current path
	update_env(ft_strdup("OLDPWD"), ft_strdup(get_env_value("PWD")));
	update_env(ft_strdup("PWD"), path);
	return (EXIT_SUCCESS); //SUCCESS
}
