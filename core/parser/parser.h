/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:47:41 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/15 18:27:22 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# define G_REDIRECT_ERR ">"
# define L_REDIRECT_ERR "<"
# define S_QUOTE_ERR "\'"
# define D_QUOTE_ERR "\""
# define PIPE_SYN_ERR "|"
# define SC_SYN_ERR ";"
# define NO_FILE_NAME_ERR "no file name"
# define DIR_NAME_ERR "file name is a directory"
# define CHAR_ESC_ERR "escape character not satisfyed"
# define SYNTAX_ERROR 258
# define CMMAND_NOT_FOUND 127
# include "stdout/out.h"
# include <stdlib.h>
# include <stdio.h>

t_string		*g_envp;
int				g_error;
int				g_flag;
int				g_counter;
char			g_char;
t_string		g_err_msg;
typedef enum	e_bool
{
	false = 0,
	true = 1
}				t_bool;

typedef struct	s_redirect
{
	char		type;
	int			fd;
	t_string	file_name;
}				t_redirect;

typedef struct	s_command
{
	t_string			*args;
	t_redirect			*redirections;
	struct s_command	*next;
}				t_command;
t_command		*parser(t_string line);
void			libre_2d(char **arr);
t_bool			includes(t_string string, t_string pattern);
t_bool			equals(t_string s1, t_string s2);
size_t			length(t_string string);
t_bool			is_quote(t_bool is_file, t_string string);
t_string		trim(t_string string);
t_bool			syntax_checker(t_string line);
t_bool			check_args(t_string line);
t_bool			check_file(t_string line);
t_bool			check_file_name(t_string line);
t_bool			semi_colone_pipe_checker(t_string line);
t_bool			char_escape(t_string line);
void			escape_spaces(t_string line);
t_bool			is_redirection(char c);
#endif
