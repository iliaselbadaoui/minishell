/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../parser.h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:13:49 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/31 11:03:47 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

static void	load_history()
{
	char	*line;
	
	g_container->history_file = open(".history", O_RDONLY|O_CREAT, 0666);
	while (in(g_container->history_file, &line))
	{
		if (*line != 0)
			add_node(line, 1);
		free(line);
	}
	free(line);
	close(g_container->history_file);
}

static void	concat_line(char **line, char *c)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, c);
	free(tmp);
	tmp = NULL;
}

char		*readline()
{
	int				done;
	int				total;
	char			*res;

	done = 1;
	if (!g_container->history)
		load_history();
	res = ft_strdup("");
	while (done)
	{
		total = ft_getchar();
		if (total >= 32 && total < 127)
		{
			write(1, &total, sizeof(int));
			concat_line(&res, (char *)&total);
		}
		if (total == KEY_UP)
			up_history(&res, ft_strlen(res));
		if (total == KEY_DOWN)
			down_history(&res, ft_strlen(res));
		if (total == KEY_REMOVE)
			backspace(&res, ft_strlen(res));
		if (total == CTRL_D)
			if (ft_strlen(res) == 0)
			{
				out("exit\n");
				exit(g_container->error);
			}
		if (total == ENTER)
			newline(res, &done);
	}
	return (res);
}
