/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x10000 <0x10000@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:55:26 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/22 13:35:18 by 0x10000          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

static t_bool	is_option_n(t_string str)
{
	int i;

	i = 0;
	if (str[i] == '-' && str[++i] == 'n')
	{
		while (str[++i] == 'n' || str[i] == 'e');
		if (str[i] == '\0')
			return (true);
		return (false);
	}
	return (false);
}

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
	while (args[++i])
		if (is_option_n(filter(args[i])))
			n_option++;
		else
			break ;
	while (args[i])
	{
		str = filter(args[i++]);
		if (*str == '\0')
			continue ;
		if (tmp)
			write(fd, " ", 1);
		write(fd, str, ft_strlen(str));
		tmp = true;
	}
	if (!n_option)
		write(fd, "\n", 1);
	return (0); // SUCCESS
}
