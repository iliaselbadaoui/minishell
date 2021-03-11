/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:06:00 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/11 15:06:52 by mait-si-         ###   ########.fr       */
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

t_map			*g_map;

int			exec_cmds(t_command *list);
void		signal_handler(int signo);
int			check_builtins(t_command *cmd);
int			check_bins(t_command *cmd);
t_string	get_env_value(t_string key);
t_string	filter(t_string str);
int			get_next_line(int fd, char **line);

// Builtin Functions
int			env(void);
int			pwd(void);
int			exit_shell(t_command *cmd);
int			echo(t_string *args, int fd);
int			export(t_string *args);
int			unset(void);
int			cd(void);

// Libft funcions
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isdigit(int c);
int			ft_isalpha(int c);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strcpy(char *dst, const char *src);
void		*ft_calloc(size_t count, size_t size);

// Tmp functionss
void		print_struct(t_command *list);


#endif
