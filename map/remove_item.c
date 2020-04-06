/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 12:23:19 by ielbadao          #+#    #+#             */
/*   Updated: 2020/04/06 12:39:35 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void    remove_item(t_map *map, t_map *item)
{
    if(item == map)
    {
        map = map->next;
        safe_free(item);
    }
    while (map)
    {
        if(map->next == item)
        {
            map->next = item->next;
            safe_free(item);
            return ;
        }
        map = map->next;
    }
}