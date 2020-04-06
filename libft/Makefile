COM = gcc
FLAGS = -Wall -Werror -Wextra -c

SRCS =	libft/ft_abs.c libft/ft_match_conversion.c libft/ft_strchr.c libft/ft_atoi.c libft/ft_memccpy.c libft/ft_strdup.c\
		libft/ft_bzero.c libft/ft_memchr.c libft/ft_strjoin.c libft/ft_calloc.c libft/ft_memcmp.c libft/ft_strlcat.c\
		libft/ft_char_times.c libft/ft_memcpy.c libft/ft_strlcpy.c libft/ft_finder.c libft/ft_memmove.c libft/ft_strlen.c\
		libft/ft_inits.c libft/ft_memset.c libft/ft_strmapi.c libft/ft_isalnum.c libft/ft_mix_help.c libft/ft_strncmp.c\
		libft/ft_isalpha.c libft/ft_mix_help_2.c libft/ft_strnstr.c libft/ft_isascii.c libft/ft_mixed_flags.c libft/ft_strrchr.c\
		libft/ft_isdigit.c libft/ft_nb_length.c libft/ft_strtrim.c libft/ft_isprint.c libft/ft_point_process.c libft/ft_substr.c\
		libft/ft_itoa.c libft/ft_print_type.c libft/ft_to_hex.c libft/ft_printf.c libft/ft_tolower.c\
		libft/ft_processor.c libft/ft_toupper.c libft/ft_putchar_fd.c libft/ft_type_len.c\
		libft/ft_putendl_fd.c libft/ft_zero_process.c libft/ft_putnbr_fd.c libft/ft_zeros_spaces.c\
		libft/ft_putnbr_u_fd.c libft/get_next_line.c libft/ft_putstr_fd.c libft/get_next_line_utils.c\
		libft/ft_split.c libft/star_help.c libft/ft_star_process.c libft/safe_malloc.c libft/safe_free.c libft/collect_garbage.c
BONUS = libft/ft_lstadd_back_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstclear_bonus.c libft/ft_lstdelone_bonus.c libft/ft_lstiter_bonus.c\
		libft/ft_lstlast_bonus.c libft/ft_lstmap_bonus.c libft/ft_lstnew_bonus.c libft/ft_lstsize_bonus.c
OBJ =	ft_abs.o ft_match_conversion.o ft_strchr.o ft_atoi.o ft_memccpy.o ft_strdup.o\
		ft_bzero.o ft_memchr.o ft_strjoin.o ft_calloc.o ft_memcmp.o ft_strlcat.o\
		ft_char_times.o ft_memcpy.o ft_strlcpy.o ft_finder.o ft_memmove.o ft_strlen.o\
		ft_inits.o ft_memset.o ft_strmapi.o ft_isalnum.o ft_mix_help.o ft_strncmp.o\
		ft_isalpha.o ft_mix_help_2.o ft_strnstr.o ft_isascii.o ft_mixed_flags.o ft_strrchr.o\
		ft_isdigit.o ft_nb_length.o ft_strtrim.o ft_isprint.o ft_point_process.o ft_substr.o\
		ft_itoa.o ft_print_type.o ft_to_hex.o ft_printf.o ft_tolower.o\
		ft_processor.o ft_toupper.o ft_putchar_fd.o ft_type_len.o\
		ft_putendl_fd.o ft_zero_process.o ft_putnbr_fd.o ft_zeros_spaces.o\
		ft_putnbr_u_fd.o get_next_line.o ft_putstr_fd.o get_next_line_utils.o\
		ft_split.o star_help.o ft_star_process.o
BONUS_OBJ =	ft_lstadd_back_bonus.o ft_lstadd_front_bonus.o ft_lstclear_bonus.o ft_lstdelone_bonus.o ft_lstiter_bonus.o\
			ft_lstlast_bonus.o ft_lstmap_bonus.o ft_lstnew_bonus.o ft_lstsize_bonus.o

NAME = libft.a
INC = -I libft.h -I ft_printf.h -I get_next_line.h -I g_collect.h
ALLOBJ = $(wildcard *.o)
all: $(NAME)
	
$(NAME):
	@$(COM) $(FLAGS) $(SRCS) $(INC)
	@ar rc $(NAME) $(OBJ)
bonus : 
	@$(COM) $(FLAGS) $(BONUS)
	@ar rc $(NAME) $(BONUS_OBJ)
clean :
	@rm -f $(ALLOBJ)
fclean : clean
	@rm -f $(NAME)
re : fclean all clean
.PHONY: all clean fclean re