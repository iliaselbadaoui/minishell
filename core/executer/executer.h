/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:06:00 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/10 19:13:48 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H
# include "../parser/parser.h"
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

t_map			*g_map;

int		exec_cmds(t_command *list);
void	signal_handler(int signo);
int		check_builtins(t_command *cmd);
int		check_bins(t_command *cmd);
int		exit_shell(t_command *cmd);

// Builtin Functions
int		echo(t_string *args);
int		env(void);
int		pwd(void);
int		cd(void);
int		export(void);
int		unset(void);

// Libft funcions
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);

#endif
