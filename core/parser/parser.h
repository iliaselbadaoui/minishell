/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 16:14:05 by ielbadao          #+#    #+#             */
/*   Updated: 2020/07/03 11:31:42 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# define CODE
# include <stdlib.h>
# include "ft_printf.h"

typedef struct	s_part
{
	int				pipe_id;
	char			*command;
	char			**args;
	struct s_part	*next;
}				t_part;
size_t		length(char *string);
char		**pipes(char *string);
char		**parts(char *string);
char		**arg_finder(char *cmd);
void		add_part(t_part **head, t_part *part);
void		free_double_char_arr(char **arr);
t_part		*sequencer(char *cmd);
t_part		*parser(char *line);
int			equals(char *s1, char *s2);
char		**get_path();
int			get_dir(const char *path, const char *command);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
#endif
