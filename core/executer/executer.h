/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:06:00 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/23 20:28:27 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H
# include "../parser/parser.h"
# include "../parser/stdin/in.h"
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# define MAX_INT 2147483647
# ifndef BUFFER_SIZEE
#  define BUFFER_SIZEE 32
# endif

// Tmp functionss
void		print_struct(t_command *list);

// Builtin Functions
int			env(void);
int			pwd(void);
int			exit_shell(t_command *cmd);
int			echo(t_string *args);
int			export(t_string *args);
int			unset(t_string *args);
int			cd(t_string *args);

// Libft funcions
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isdigit(int c);
int			ft_isalpha(int c);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strcpy(char *dst, const char *src);
void		*ft_calloc(size_t count, size_t size);

// Utils
void		signal_handler(int signo);
void		proc_signal_handler(int signo);
t_bool		key_exist(t_map *head, t_string key);
t_bool		is_valid_key(t_string key);
int			no_file(t_string path);
int			not_valid(t_string key, t_string value);
t_string	get_env_value(t_string key);
int			get_error(int ret);
void		free_2d_arr(char **arr);
void		sort_env(void);
void		clone_env(void);

int			entry(t_command *list);
int			check_bins(t_command *cmd);
t_string	filter(t_string str);
int			get_next_line(int fd, char **line);
void		update_env(t_string key, t_string value);
int			check_redirection(t_command *list);
t_command	*handle_pipes(t_command *cmd);
int			exec_command(t_command *list);

#endif
