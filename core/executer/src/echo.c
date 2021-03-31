/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:55:26 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/31 13:35:36 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

// Check valid option n
static t_bool	is_valid_option_n(t_string str)
{
	int i;

	i = 0;
	if (str[i] == '-' && str[++i] == 'n')
	{
		while (str[++i] == 'n');
		if (str[i] == '\0')
		{
			free(str);
			return (true);
		}
		free(str);
		return (false);
	}
	free(str);
	return (false);
}

// Check if there is -n option
static void		check_option(t_string *args, int *i, int *n_option)
{
	while (args[++*i])
		if (is_valid_option_n(filter(ft_strdup(args[*i]))))
			(*n_option)++;
		else
			return ;
}

// Print a string
int				echo(t_string *args, int fd)
{
	int			i;
	int			j;
	int			n_option;
	t_string	str;
	t_bool		tmp;

	n_option = 0;
	i = 0;
	j = -1;
	tmp = false;
	check_option(args, &i, &n_option);
	while (args[i])
	{
		str = filter(ft_strdup(args[i++]));
		if (*str == '\0')
		{
			free(str);
			continue ;
		}
		if (tmp)
			write(fd, " ", 1);
		write(fd, str, ft_strlen(str));
		free(str);
		tmp = true;
	}
	if (!n_option)
		write(fd, "\n", 1);
	return (0); // SUCCESS
}
