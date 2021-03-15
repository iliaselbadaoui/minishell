/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:21:53 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/15 11:27:00 by mait-si-         ###   ########.fr       */
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
	write(fd, get_env_value(name), ft_strlen(get_env_value(name)));
	free(name);
	// Return index (to keep printing the rest of strings)
	return (i - 1);
}

int				double_quote(t_string str, int j, int fd)
{
	while (str[++j] && str[j] != '"')
		if (str[j] == '$')
			j = print_variable(str, j, fd);
		else
			write(fd, &str[j], 1);
	return (j);
}

t_string	filter(t_string str)
{
	int			i;
	int			fd;
	t_string	line;

	i = -1;
	fd = open("tmp.txt", O_RDWR|O_APPEND);
	while (str[++i])
		if (str[i] == '\\')
			write(fd, &str[++i], 1);
		else if (str[i] == '\'')
			while (str[++i] && str[i] != '\'')
				write(fd, &str[i], 1);
		else if (str[i] == '"')
			i = double_quote(str, i, fd);
		else if (str[i] == '$')
			i = print_variable(str, i, fd);
		else
			write(fd, &str[i], 1);
	close(fd);
	fd = open("tmp.txt", O_RDONLY);
	get_next_line(fd, &line);
	close(fd);
	fd = open("tmp.txt", O_RDONLY | O_WRONLY | O_TRUNC);
	close(fd);
	return (line);
}
