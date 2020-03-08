/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 10:35:08 by ielbadao          #+#    #+#             */
/*   Updated: 2020/03/08 10:40:09 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../types.h"

int			contains(t_string container, t_string content);
int			equals(t_string s1, t_string s2);
int			line_parser(t_string line);
#endif
