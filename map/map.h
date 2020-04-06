/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 14:17:54 by ielbadao          #+#    #+#             */
/*   Updated: 2020/04/06 12:48:28 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "../types.h"
# include "../libft/g_collect.h"
# include "../libft/ft_printf.h"

typedef struct  s_map
{
    t_string        key;
    t_string        value;
    struct s_map    *next;
}               t_map;
t_map   *g_map;
t_map   *get_last_item(t_map *map);
t_map   *init_item(key, value);
void    insert_item(t_map *map,t_map *item);
void    remove_item(t_map *map, t_map *item);
void    clear_map(t_map *map);
#endif
