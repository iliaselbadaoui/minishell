/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:43:49 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/18 20:47:41 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void				free_map_node(t_map *tmp)
{
	free(tmp->key);
	free(tmp->value);
	free(tmp);
}
