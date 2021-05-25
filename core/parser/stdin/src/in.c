/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 13:32:12 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 23:50:59 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../in.h"

void	fill_line(char **line, char *buffer)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, buffer);
	ft_free(&tmp);
}

int	process_line(char **line, char **remain)
{
	char	*nl;
	char	*tmp;

	nl = ft_strchr(*line, '\n');
	if (nl)
	{
		*nl = '\0';
		tmp = *line;
		*line = ft_strdup(*line);
		*remain = ft_strdup(nl + 1);
		ft_free(&tmp);
		return (1);
	}
	return (0);
}

int	process_remain(char **remain, char **line)
{
	char	*nl;
	char	*tmpr;
	char	*tmpl;

	nl = ft_strchr(*remain, '\n');
	if (nl)
	{
		*nl = '\0';
		tmpl = *line;
		tmpr = *remain;
		*line = ft_strdup(*remain);
		*remain = ft_strdup(nl + 1);
		ft_free(&tmpl);
		ft_free(&tmpr);
		return (1);
	}
	tmpl = *line;
	*line = ft_strdup(*remain);
	ft_free(&tmpl);
	ft_free(remain);
	return (0);
}

static int	in_help(char **remain, char **buffer, char **line, int fd)
{
	*buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (read(fd, NULL, 0) || BUFFER_SIZE < 0 || !line || !*buffer)
		return (-1);
	*line = ft_strdup("\0");
	if (remain[fd] && process_remain(&remain[fd], line))
	{
		ft_free(buffer);
		return (1);
	}
	return (0);
}

int	in(int fd, char **line)
{
	static char	*remain[256];
	char		*buffer;
	int			bytes;
	int			ret;

	ret = in_help(remain, &buffer, line, fd);
	if (ret == 1 || ret == -1)
		return (ret);
	while (1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		fill_line(line, buffer);
		if (process_line(line, &remain[fd]))
		{
			ft_free(&buffer);
			return (1);
		}
	}
	ft_free(&buffer);
	return (0);
}
