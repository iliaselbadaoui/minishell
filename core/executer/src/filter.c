/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:21:53 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/27 19:38:11 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

// Check next character after $ symbole
static int	check_characters(t_string str, int i, int fd)
{
	if (str[i] == '?')
	{
		ft_putnbr_fd(g_container->error, fd);
		return (i);
	}
	else if (str[i] == ' ' || str[i] == '\0' || str[i] == '"')
	{
		write(fd, "$", 1);
		return (i);
	}
	else if (str[i] && (ft_isdigit(str[i]) || (!ft_isalpha(str[i]) && str[i] != '_')))
		return (i);
	return (0);
}

// replace Variables with their values
static int	print_variable(t_string str, int i, int fd)
{
	int				start;
	int				end;
	t_string		name;
	int				ret;
	t_string		value;

	start = ++i;
	end = start - 1;
	// Check characters
	ret = check_characters(str, i--, fd);
	if (ret)
		return (ret);
	// Count variable length
	while (str[++i] && (ft_isalpha(str[i]) || ft_isdigit(str[i]) || str[i] == '_'))
		end++;
	// Extract variable name
	name = substring(str, start, end);
	// Print variable value
	value = get_env_value(name);
	free(name);
	if (value)
		write(fd, value, ft_strlen(value));
	return (i - 1); // Return index (to keep printing the rest of strings)
}

// Write everything inside "" exactly as it is, and replace Variables with their values
static int	double_quote(t_string str, int j, int fd)
{
	while (str[++j] && str[j] != '"')
	{
		if (str[j] == '$')
			j = print_variable(str, j, fd);
		else
			write(fd, &str[j], 1);
	}
	return (j);
}

// Get data from the file and clean it
static t_string	get_data(void)
{
	int			fd;
	t_string	line;

	fd = open("/tmp/.tmp", O_RDONLY, 0666);
	get_next_line(fd, &line);
	close(fd);
	fd = open("/tmp/.tmp", O_RDONLY | O_WRONLY | O_TRUNC, 0666);
	close(fd);
	return (line);
}

// Return a clean string. eg: "Hello "$USER to == '$HOME'  ===>  Hello mait-si- to == $HOME
t_string	filter(t_string str)
{
	int			i;
	int			fd;

	i = -1;
	fd = open("/tmp/.tmp", O_RDWR | O_APPEND | O_CREAT, 0666);
	while (str[++i])
	{
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
	}
	close(fd);
	free(str);
	return (get_data());
}
