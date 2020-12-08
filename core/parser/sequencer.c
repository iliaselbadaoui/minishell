/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequencer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 22:23:34 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/08 10:57:28 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*get_cmd_name(char **cmd)
{
	int		i;
	int		pos;
	char	holder;
	char	*com;

	i = 0;
	while (**cmd == ' ')
		(*cmd)++;
	if ((*cmd)[i] == '"' || (*cmd)[i] == 39)
	{
		holder = (*cmd)[i];
		(*cmd)++;
	}
	while ((*cmd)[i] != ' ' && (*cmd)[i] && (*cmd)[i] != holder)
		i++;
	if (!i)
		return (NULL);
	com = (char *)malloc(i+1);
	com[i] = '\0';
	pos = i+1;
	while (i-- > -1)
	{
		com[i] = (*cmd)[i];
	}
	*cmd += pos;
	return (com);
}

t_part		*sequencer(char *cmd, int id)
{
	t_part	*prt;

	if (!(prt = (t_part *)malloc(sizeof(t_part))))
		return (NULL);
	if (!(prt->command = get_cmd_name(&cmd)))
	{
		free(prt);
		return (NULL);
	}
	if (!(prt->args = arg_finder(cmd)))
	{
		free(prt);
		return (NULL);
	}
	prt->pipe_id = id;
	prt->next = NULL;
	return (prt);
}
