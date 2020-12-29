/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:50:19 by ielbadao          #+#    #+#             */
/*   Updated: 2020/11/25 11:22:34 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H
# include <stdlib.h>
# include <stdio.h>

char		**ft_split(char *str, char delimiter);
int			ft_count(char *str, char delimiter);
void		escape_deilimter(char **str, char delimiter);
void		create_grid(char **arr, char *str, char delimiter);
void		fill_grid(char **arr, char *str, char delimiter);
#endif
