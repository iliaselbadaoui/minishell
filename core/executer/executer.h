/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:06:00 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/01 10:51:28 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H
# include "../parser/parser.h"

int		exec_cmds(t_command *list);
int		ft_strcmp(const char *s1, const char *s2);
void	signal_handler(int signo);

#endif
