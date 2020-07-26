/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 23:19:17 by ielbadao          #+#    #+#             */
/*   Updated: 2020/07/09 18:32:42 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <dirent.h>

int			get_dir(const char *path, const char *command)
{
	DIR				*dir;
	struct dirent	*ent;

	dir = opendir(path);
	readdir(dir);
	readdir(dir);
	while ((ent = readdir(dir)))
	{
		if(equals(ent->d_name, (char * )command))
		{
			closedir(dir);
			return (1);
		}
	}
	closedir(dir);
	return (0);
}
