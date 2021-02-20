/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:55:26 by mait-si-          #+#    #+#             */
/*   Updated: 2021/02/20 19:01:42 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

int	is_special_character(t_string arg, int i)
{
	if (arg[i] == '\'')
		while (arg[++i] != '\'')
			write(1, &arg[i], 1);
	// else if (arg[i] == '"')
	// {
	// 	if (arg[++i] == '$')
	// 		while (arg[++i] != '"')
	// 			write(1, "-", 1);
	// 	else
	// 		write(1, &arg[i], 1);
	// }
	// else
	// 	while (arg[++i] != ' ' && arg[i])
	// 		write(1, "-", 1);
	return (i);
}

int		print_variable(t_string str,int i, int fd)
{
	t_string variable;

	variable = NULL;
	if (str[i] == ' ' || str[i] == '\0')
		write(fd, "$", 1);
	else if (!ft_isalpha(str[i]) && str[i] != '_')
		write(fd, &str[++i], 1);
	else
		while (str[i] && (ft_isalpha(str[i]) || ft_isdigit(str[i]) || str[i] == '_'))
		{
			// write(fd, &str[i++], 1);
			write(fd, ".", 1);
			i++;
		}
	return (i);
}

int		echo(t_string *args, int fd)
{
	int	i;
	int	j;

	i = 0;
	while (args[++i])
	{
		j = -1;
		while (args[i][++j])
			if (args[i][j] == '\\')
				write(fd, &args[i][++j], 1);
			else if (args[i][j] == '\'')
				while (args[i][++j] && args[i][j] != '\'')
					write(fd, &args[i][j], 1);
			else if (args[i][j] == '"')
				while (args[i][++j] && args[i][j] != '"')
					if (args[i][j] == '$')
						j = print_variable(args[i], ++j, fd);
					else
						write(fd, &args[i][j], 1);
			else if (args[i][j] == '$')
				j = print_variable(args[i], ++j, fd);
			else
				write(fd, &args[i][j], 1);
	}
	write(fd, "\n", 1);
	return (1);
}
