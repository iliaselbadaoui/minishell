/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:55:26 by mait-si-          #+#    #+#             */
/*   Updated: 2021/03/16 13:01:29 by mait-si-         ###   ########.fr       */
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

	n_option = 0;
	i = 0;
	j = -1;
	while (args[++i])
		if (is_option_n(filter(args[i])))
			n_option++;
		else
			break ;
	while (args[i])
	{
		str = filter(args[i++]);
		if (*str != '\0' && n_option < i - 2)
			write(fd, " ", 1);
		write(fd, str, ft_strlen(str));
	}
	if (!n_option)
		write(fd, "\n", 1);
	return (1);
}
