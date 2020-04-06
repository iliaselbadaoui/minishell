/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_collect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:00:34 by ielbadao          #+#    #+#             */
/*   Updated: 2020/03/07 16:30:55 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_COLLECT_H
# define G_COLLECT_H
# define SUCCESS 1
# define FAIL 0
#include <stdlib.h>
#include <sys/types.h>

typedef struct	s_collection
{
	void				*data;
	struct s_collection	*next;
}				t_collection;

t_collection		*g_collection;
void				*safe_malloc(ssize_t size);
int					safe_free(void *ptr);
int					collect_garbage();
#endif