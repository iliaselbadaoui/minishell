/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:55:26 by mait-si-          #+#    #+#             */
/*   Updated: 2021/02/25 18:52:55 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

int				print_variable(t_string str, int i, int fd)
{
	int				start;
	int				end;
	t_string		name;

	start = ++i;
	end = start -1 ;
	name = ft_strdup("");
	// Check characters
	if (str[i] == '?')
	{
		ft_putnbr_fd(g_error, fd);
		return (i);
	}

	if (str[i] == ' ' || str[i] == '\0' || str[i] == '"')
	{
		write(fd, "$", 1);
		return (i);
	}
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
	// Print variable value
	out(get_env_value(name));
	free(name);
	// Return index (to keep printing the rest of strings)
	return (i - 1);
}

int				double_quote(t_string str, int j, int fd)
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

void			put_argument(t_string str, int fd, int j)
{
	while (str[++j])
		if (str[j] == '\\')
			write(fd, &str[++j], 1);
		else if (str[j] == '\'')
			while (str[++j] && str[j] != '\'')
				write(fd, &str[j], 1);
		else if (str[j] == '"')
			j = double_quote(str, j, fd);
		else if (str[j] == '$')
			j = print_variable(str, j, fd);
		else
			write(fd, &str[j], 1);
}

int				echo(t_string *args, int fd)
{
	int			i;
	int			j;
	t_bool		n_option;

	i = 0;
	n_option = false;
	while (args[++i])
	{
		j = 0;
		if (args[i][0] == '-' && args[i][1] == 'n')
		{
			while (args[i][++j])
				if (args[i][j] == 'n')
					n_option = true;
				else
				{
					n_option = false;
					break ;
				}
		}
		if (n_option)
			continue ;
		j = n_option ? 0 : -1;
		put_argument(args[i], fd, j);
	}
	if (!n_option)
		write(fd, "\n", 1);
	return (1);
}
