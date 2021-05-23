/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backspace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:38:39 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 11:10:59 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	backspace(char **line, int line_length)
{
	char	*tmp;

	if (line_length > 0)
	{
		tmp = *line;
		tmp[line_length - 1] = 0;
		*line = ft_strdup(tmp);
		free(tmp);
		tputs(tgetstr("le", NULL), 1, move_cursor);
		tputs(tgetstr("ce", NULL), 1, move_cursor);
		line_length--;
	}
}
