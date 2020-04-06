/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 11:37:40 by ielbadao          #+#    #+#             */
/*   Updated: 2020/04/06 12:20:06 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map   *init_item(key, value)
{
    t_map *item;

    if(!(item = (t_map *)safe_malloc(sizeof(t_map))))
    {
        ft_colored_output(RED, "An Error has occured");
        exit(FAIL);
    }
    item->next = NULL;
    return (item);
}
