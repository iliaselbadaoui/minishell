/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:55:26 by mait-si-          #+#    #+#             */
/*   Updated: 2021/05/26 17:58:32 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

// Check valid option n
static t_bool	is_valid_option_n(t_string str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && str[++i] == 'n')
	{
		while (str[++i] == 'n')
			continue ;
		if (str[i] == '\0')
			return (true);
		return (false);
	}
	return (false);
}

// Check if there is -n option
static void	check_option(t_string *args, int *i, int *n_option)
{
	while (args[++*i])
	{
		if (is_valid_option_n(args[*i]))
			(*n_option)++;
		else
			return ;
	}
}

static void	loop(t_string *args, int i)
{
	t_bool		tmp;

	tmp = false;
	while (args[++i])
	{
		if (args[i][0] == '\0')
			continue ;
		if (tmp)
			write(1, " ", 1);
		write(1, args[i], ft_strlen(args[i]));
		tmp = true;
	}
}

// Main echo Function
int	echo(t_string *args)
{
	int	position;
	int	n_option;

	n_option = 0;
	position = 0;
	check_option(args, &position, &n_option);
	loop(args, position - 1);
	if (!n_option)
		write(1, "\n", 1);
	return (0);
}
