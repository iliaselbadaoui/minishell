/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:28:53 by mait-si-          #+#    #+#             */
/*   Updated: 2021/02/06 15:07:07 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executer.h"

int		cd()
{
	out("cd still need work \n");
	return (1);
}

int		pwd(void)
{
	char	buff[1024];

	if (getcwd(buff, sizeof(buff)) == NULL)
		return (-1);
	out(buff);
	out("\n");
	return (1);
}

int		export(void)
{
	out("export still need work \n");
	return (1);
}

int		unset()
{
	out("unset still need work \n");
	return (1);
}

int		env(void)
{
	t_map	*tmp;

	tmp = g_map;
	while (tmp)
	{
		out(tmp->key);
		out("=");
		out(tmp->value);
		out("\n");
		tmp = tmp->next;
	}
	return (1);
}
