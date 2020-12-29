/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:47:41 by ielbadao          #+#    #+#             */
/*   Updated: 2020/12/29 22:33:50 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# define SYNTAX_ERROR 258
# define NO_FILE_DIR 1
# define CMMAND_NOT_FOUND 127
# include "stdout/out.h"
# include "stdin/in.h"
# include "split/ft_split.h"
# include <stdlib.h>
# include <stdio.h>

t_string		*g_envp;
int				g_error;
int				g_flag;
int				g_counter;
int				g_counter_extra;
int				g_spliter_counter;
int				g_spliter_char;
char			g_char;

typedef enum	e_bool
{
	false = 0,
	true = 1
}				t_bool;

typedef struct	s_map
{
	t_string		key;
	t_string		value;
	struct s_map	*next;
}				t_map;

typedef struct	s_redirect
{
	char		type;
	int			fd;
	t_string	file_name;
}				t_redirect;

typedef struct	s_coord
{
	int			start;
	int			end;
	char		type;
}				t_coord;

typedef struct	s_command
{
	int					id;
	t_string			*args;
	t_redirect			*redirections;
	struct s_command	*next;
}				t_command;

t_command		*parser(t_string line);
void			libre_2d(char **arr);
t_bool			includes(t_string string, t_string pattern);
t_bool			equals(t_string s1, t_string s2);
size_t			length(t_string string);
t_string		ft_itoa(int n);
t_bool			is_quote(t_bool is_file, t_string string);
t_bool			check_quote(char c);
t_string		trim(t_string string);
t_bool			syntax_checker(t_string line);
t_bool			check_args(t_string line);
t_bool			check_file(t_string line);
t_bool			greate_question(t_string line);
t_bool			check_file_name(t_string line);
t_bool			semi_colone_pipe_checker(t_string line);
t_bool			char_escape(t_string line);
void			escape_spaces(t_string line);
int				sequence_calculator(t_string line, char delimiter);
int				get_next_delimiter(t_string line, char delimiter);
t_string		substring(t_string string, int start, int end);
void			skip_word(t_string command);
void			skip_redirection(t_string command);
void			skip_spaces(t_string command);
t_string		*spliter(t_string line, char delimiter);
t_bool			is_redirection(char c);
t_string		*args_extracter(t_string command);
int				args_calculator(t_string command);
t_coord			get_next_arg(t_string line);
t_redirect		*redirections_extracter(t_string command);
int				redirections_calculator(t_string command);
t_coord			get_next_redirection(t_string line);
t_command		*init_command(t_string *args, t_redirect *redirections, int id);
void			add_command_to_end(t_command **head, t_command *node);
void			free_commands(t_command **head);
void			free_redirection(t_redirect	**redirection);
t_map			*init_map(t_string key, t_string value);
void			add_to_map(t_map **head, t_map	*node);
t_string		get_value_by_key(t_map *head, t_string key);
void			free_by_key(t_map **head, t_string key);
void			free_map(t_map	**head);
t_map			*fill_env(t_string *envp);
#endif
