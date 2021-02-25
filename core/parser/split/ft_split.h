/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:50:19 by ielbadao          #+#    #+#             */
/*   Updated: 2021/02/11 14:22:09 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H
# include <stdlib.h>
# include <stdio.h>

int			g_flag;

char		**ft_split(char *str, char delimiter);
char		**ft_split_first(char *str, char delimiter);
int			ft_count(char *str, char delimiter);
void		escape_deilimter(char **str, char delimiter);
void		create_grid(char **arr, char *str, char delimiter);
void		create_grid_first(char **arr, char *str, char delimiter);
void		fill_grid(char **arr, char *str, char delimiter);
void		fill_grid_first(char **arr, char *str, char delimiter);
#endif
