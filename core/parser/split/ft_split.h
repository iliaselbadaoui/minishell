/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-si- <mait-si-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:50:19 by ielbadao          #+#    #+#             */
/*   Updated: 2021/05/28 16:14:23 by mait-si-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H
# include <stdlib.h>
# include <stdio.h>

typedef char *t_string;
typedef enum e_bool
{
	false = 0,
	true = 1,
	quantic = 2
}				t_bool;

typedef struct s_map
{
	t_string		key;
	t_string		value;
	struct s_map	*next;
}				t_map;

typedef struct s_redirect
{
	char		type;
	int			fd;
	t_string	file_name;
}				t_redirect;

typedef struct s_coord
{
	int			start;
	int			end;
	char		type;
}				t_coord;

typedef struct s_command
{
	int					id;
	int					pos;
	t_string			*args;
	t_redirect			*redirections;
	struct s_command	*next;
}				t_command;

typedef struct s_linked
{
	char			*cmd;
	char			*cmd_tmp;
	int				editing;
	int				already;
	int				is_visited;
	struct s_linked	*next;
	struct s_linked	*prev;
}				t_linked;

typedef struct s_container
{
	t_string		*envp;
	char			term_buffer[2048];
	int				error;
	int				flag;
	int				map_fill_first_time;
	int				counter;
	int				args_counter;
	int				counter_extra;
	int				spliter_counter;
	int				spliter_char;
	int				envp_count;
	char			gchar;
	char			*res;
	int				history_file;
	int				history_iter;
	int				is_segint;
	int				is_process;
	t_linked		*last;
	t_linked		*history;
	t_linked		*history_to_free;
	t_linked		*history_the_oldest;
	t_map			*map;
	t_map			*sorted_env;
}	t_container;

t_container	*g_container;
char		**ft_split(char *str, char delimiter);
char		**ft_split_first(char *str, char delimiter);
int			ft_count(char *str, char delimiter);
void		escape_deilimter(char **str, char delimiter);
void		create_grid(char **arr, char *str, char delimiter);
void		create_grid_first(char **arr, char *str, char delimiter);
void		fill_grid(char **arr, char *str, char delimiter);
void		fill_grid_first(char **arr, char *str, char delimiter);
#endif
