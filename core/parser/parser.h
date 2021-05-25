/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 09:37:03 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/25 17:36:47 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# define SYNTAX_ERROR 258
# define NO_FILE_DIR 1
# define CMMAND_NOT_FOUND 127
# define KEYCODE_U 0x41
# define KEYCODE_D 0x42
# define KEY_UP 183
# define KEY_DOWN 184
# define KEY_LEFT 186
# define KEY_RIGHT 185
# define ENTER 10
# define KEY_REMOVE 127
# define KEY_TAB 9
# define CTRL_D 4
# define CTRL_C 3
# include "./stdout/out.h"
# include "./stdin/in.h"
# include "./split/ft_split.h"
# include <stdlib.h>
# include <stdio.h>
# include <termcap.h>
# include <termios.h>
# include <sys/ioctl.h>

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
void			free_map_node(t_map *tmp);
int				free_head(t_map **head, t_string key);
t_map			*fill_env(t_string *envp);
void			envp_handler(t_string	*envp);
t_bool			is_option(t_string arg);
void			add_to_envp(t_string key, t_string value);
void			remove_from_envp(int index);
t_string		delete_quotes(t_string str);
t_string		variable_name_extracter(t_string str);
t_bool			greate_question_quote(t_string line);
int				init_caps(void);
int				ft_getchar(void);
char			*readline(void);
int				move_cursor(int d);
void			up_history(char **line, int line_length);
void			backspace(char **line, int line_length);
void			down_history(char **line, int line_length);
void			newline(char	*line, int *done);
void			add_node(char *cmd, int already);
void			add_node_to_free(char *cmd);
void			free_last(void);
void			free_linked_list(t_linked *history);
void			write_to_stdout(char *line);
t_linked		*get_previous(void);
t_linked		*get_next(void);
#endif
