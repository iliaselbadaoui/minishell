/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:06:00 by ielbadao          #+#    #+#             */
/*   Updated: 2021/03/11 12:49:49 by mait-si-         ###   ########.fr       */
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

t_map			*g_map;

int			exec_cmds(t_command *list);
void		signal_handler(int signo);
int			check_builtins(t_command *cmd);
int			check_bins(t_command *cmd);
t_string	get_env_value(t_string key);
t_string	filter(t_string str);

// Builtin Functions
int		env(void);
int		pwd(void);
int		exit_shell(t_command *cmd);
int		echo(t_string *args, int fd);
int		export(t_string *args);
int		unset(void);
int		cd(void);

// Libft funcions
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
void	ft_putnbr_fd(int n, int fd);

// Tmp functionss
void	print_struct(t_command *list);


#endif
