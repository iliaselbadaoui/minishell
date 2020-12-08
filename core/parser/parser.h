/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 16:14:05 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/08 10:58:08 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# define CODE
# include <stdlib.h>
# include "ft_printf.h"

typedef	struct	s_redirection
{
	char					sense;
	char					*file_name;
	struct s_redirection	*next;
}				t_redirection;

typedef struct	s_part
{
	int				pipe_id;
	char			*command;
	char			**args;
	t_redirection	*redirections;
	struct s_part	*next;
}				t_part;

char		**g_path;
int			g_pipe_id;
size_t		length(char *string);
char		**pipes(char *string);
char		**parts(char *string);
char		**arg_finder(char *cmd);
void		add_part(t_part **head, t_part *part);
void		free_double_char_arr(char **arr);
t_part		*sequencer(char *cmd, int id);
t_part		*parser(char *line);
int			equals(char *s1, char *s2);
char		**get_path();
int			get_dir(const char *path, const char *command);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
#endif
