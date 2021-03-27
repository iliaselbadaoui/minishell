/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:21:53 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/26 21:11:12 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

static int		check_characters(t_string str, int i, int fd)
{
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
	return (0);
}

static int		print_variable(t_string str, int i, int fd)
{
	int				start;
	int				end;
	t_string		name;
	int				ret;
	t_string		value;

	start = ++i;
	end = start - 1;
	name = ft_strdup("");
	// Check characters
	if ((ret = check_characters(str, i--, fd)))
		return (ret);
	// Count variable length
	while (str[++i] && (ft_isalpha(str[i]) || ft_isdigit(str[i]) || str[i] == '_'))
		end++;
	// Extract variable name
	name = substring(str, start, end);
	// Print variable value
	value = get_env_value(name);
	write(fd, value, ft_strlen(value));
	free(name);
	// Return index (to keep printing the rest of strings)
	return (i - 1);
}

static int		double_quote(t_string str, int j, int fd)
{
	while (str[++j] && str[j] != '"')
		if (str[j] == '$')
			j = print_variable(str, j, fd);
		else
			write(fd, &str[j], 1);
	return (j);
}

static t_string	get_data(void)
{
	int			fd;
	t_string	line;

	fd = open("/tmp/tmp.txt", O_RDONLY);
	get_next_line(fd, &line);
	close(fd);
	fd = open("/tmp/tmp.txt", O_RDONLY | O_WRONLY | O_TRUNC);
	close(fd);
	return (line);
}

t_string		filter(t_string str)
{
	int			i;
	int			fd;

	i = -1;
	fd = open("/tmp/tmp.txt", O_RDWR | O_APPEND | O_CREAT);
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
	return (get_data());
}
