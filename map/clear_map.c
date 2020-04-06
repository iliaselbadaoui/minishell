/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 12:43:53 by ielbadao          #+#    #+#             */
/*   Updated: 2020/04/06 12:48:17 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void    clear_map(t_map *map)
{
    while (map != get_last_item(map))
        safe_free(map);
    safe_free(map);
}