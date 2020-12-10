/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:34:25 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/10 11:49:15 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

t_command		*parser(t_string line)
{
	t_string	*brute_entry;
	t_command	*list;

	list = NULL;
	brute_entry = NULL;
	line = NULL;
	libre_2d(brute_entry);
	return (list);
}
