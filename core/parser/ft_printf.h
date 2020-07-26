/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielbadao <ielbadao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:42:05 by ielbadao          #+#    #+#             */
/*   Updated: 2019/12/06 16:12:07 by ielbadao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_type
{
	int				i;
	unsigned int	ui;
	size_t			l;
	char			c;
	char			*s;
}				t_type;
typedef struct	s_values
{
	int		star_value;
	int		prec_value;
	int		zero_value;
}				t_values;

typedef struct	s_format_container
{
	int			star;
	int			mins;
	int			zero;
	int			prec;
	int			prec_no_spec;
	char		*conv;
	t_type		type;
	t_values	values;
}				t_format_container;
int				ft_atoi(const char *str);
int				ft_abs(int val);
void			ft_char_times(char c, int times);
int				ft_match_conversion(char conv);
void			ft_init_format(t_format_container *holder);
void			ft_init_type(t_type *type);
void			ft_processor(t_format_container container);
void			ft_point_process(t_format_container c);
void			ft_print_type(t_type t, char c);
int				ft_printable_length(int value, int length);
int				ft_finder(char *format, t_format_container *container,
				va_list *args);
int				ft_nb_length(long long int nb);
int				ft_type_len(t_type t, char c);
void			ft_print_exact_spaces(t_format_container c);
void			ft_null_prec(t_format_container c);
void			ft_to_hex(unsigned int nb, char flag);
int				ft_strlen(const char *str);
int				ft_hex_len(size_t nb);
void			ft_to_phex(size_t nb);
void			ft_pos_help(t_format_container c);
void			ft_neg_help(char c, t_type t, t_values v);
void			ft_putstr_fd(char *s, int fd, int len);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_u_fd(unsigned int n, int fd);
int				ft_putchar_fd(char c, int fd);
char			*ft_strchr(const char *s, int c);
void			ft_star_process(t_format_container c);
void			ft_mixed_flags(t_format_container c);
void			ft_help_1_2(t_format_container c);
void			ft_help_2_2(t_format_container c);
void			ft_negative_star(char c, t_type t, t_values v);
int				ft_special(int value, int length);
int				ft_zeros_spaces(int value, int length);
void			ft_zero_process(t_format_container c);
int				ft_printf(const char *format, ...);
#endif
