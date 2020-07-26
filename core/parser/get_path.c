/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:41:28 by ielbadao          #+#    #+#             */
/*   Updated: 2020/07/02 23:13:01 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../../get_next_line.h"

char	**get_path()
{
	int 	fd;
	char	*path;
	char	**res;

	fd = open("core/parser/path", O_RDONLY);
	get_next_line(fd, &path);
	close(fd);
	res = ft_split(path,':');
	return (res);
}
