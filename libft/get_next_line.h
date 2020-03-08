/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 02:47:29 by ielbadao          #+#    #+#             */
/*   Updated: 2020/03/07 19:36:08 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# define BUFFER_SIZE 256

char		*ft_strchr(const char *s, int c);
int			ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);
void		ft_free(char **p);
void		fill_line(char **line, char *buffer);
int			process_line(char **line, char **remain);
int			process_remain(char **remain, char **line);
int			get_next_line(int fd, char **line);
#endif
