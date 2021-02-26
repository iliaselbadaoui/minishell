/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:55:26 by mait-si-          #+#    #+#             */
/*   Updated: 2021/02/25 12:55:57 by mait-si-         ###   ########.fr       */
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

int		print_variable(t_string str, int i, int fd)
{
	int				start;
	int				end;
	t_string		name;

	start = ++i;
	end = start -1 ;
	name = ft_strdup("");
	// Check characters
	if (str[i] && (ft_isdigit(str[i]) || (!ft_isalpha(str[i]) && str[i] != '_')))
		return (i);
	// Count length
	while (str[i] && (ft_isalpha(str[i]) || ft_isdigit(str[i]) || str[i] == '_'))
	{
		i++;
		end++;
	}
	// Extract variable name
	name = substring(str, start, end);
	// Check variable => return index if not exist
	// Print variable value
	write(fd, "[", 1);
	out(name);
	write(fd, "]", 1);
	free(name);
	// Return index (to keep printing the rest of strings)
	return (i);
	// if (str[++i] == ' ' || str[i] == '\0')
	// 	write(fd, "$", 1);
	// else if (!ft_isalpha(str[i]) && str[i] != '_')
	// 	write(fd, &str[++i], 1);
	// else
	// 	while (str[i] && (ft_isalpha(str[i]) || ft_isdigit(str[i]) || str[i] == '_'))
	// 	{
	// 		// write(fd, &str[i++], 1);
	// 		write(fd, ".", 1);
	// 		i++;
	// 	}
	// return (i);
}

int		double_quote(t_string str, int j, int fd)
{
	while (str[++j] && str[j] != '"')
		if (str[j] == '$')
			j = print_variable(str, j, fd);
		else if (str[j] == '\\')
			write(fd, &str[++j], 1);
		else
			write(fd, &str[j], 1);
	return (j);
}

int		echo(t_string *args, int fd)
{
	int	i;
	int	j;
	int n_option;

	i = 0;
	n_option = 0;
	if (args[1][0] == '-' && args[1][1] == 'n')
		i = ++n_option;
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
				j = double_quote(args[i], j, fd);
			else if (args[i][j] == '$')
				j = print_variable(args[i], j, fd);
			else
				write(fd, &args[i][j], 1);
	}
	if (!n_option)
		write(fd, "\n", 1);
	return (1);
}
