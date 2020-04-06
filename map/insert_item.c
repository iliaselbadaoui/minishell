/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 11:54:53 by ielbadao          #+#    #+#             */
/*   Updated: 2020/04/06 12:16:15 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void    insert_item(t_map *map,t_map *item)
{
    if (!item)
    {
        ft_colored_output(RED, "An Error has occured");
        exit(FAIL);
    }
    else
    {
        get_last_item(map)->next = item;
    }
}