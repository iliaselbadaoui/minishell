/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 10:33:40 by ielbadao          #+#    #+#             */
/*   Updated: 2021/01/06 10:31:37 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_command		*init_command(t_string *args, t_redirect *redirections, int id)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	command->args = args;
	command->redirections = redirections;
	command->id = id;
	command->next = NULL;
	return (command);
}

void			add_command_to_end(t_command **head, t_command *node)
{
	t_command	*tmp;

	if (*head == NULL)
		*head = node;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

void			free_redirection(t_redirect **redirection)
{
	t_redirect	*tmp;
	t_redirect	*to_free;

	tmp = *redirection;
	while (tmp->file_name)
	{
		to_free = tmp;
		tmp++;
		free(to_free->file_name);
	}
	free(*redirection);
}

void			free_commands(t_command **head)
{
	t_command	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		libre_2d(tmp->args);
		free_redirection(&(tmp->redirections));
		free(tmp);
	}
}
