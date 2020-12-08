NAME = parser.a
CC = gcc -Wall -Werror -Wextra -c
SRCS =	src/ft_abs.c src/ft_finder.c src/ft_mix_help.c src/ft_nb_length.c src/ft_processor.c src/ft_putnbr_u_fd.c src/ft_strchr.c src/ft_type_len.c src/star_help.c \
		src/ft_atoi.c src/ft_inits.c src/ft_mix_help_2.c src/ft_point_process.c src/ft_putchar_fd.c src/ft_putstr_fd.c src/ft_strlen.c src/ft_zero_process.c \
		src/ft_char_times.c src/ft_match_conversion.c src/ft_mixed_flags.c src/ft_print_type.c src/ft_putnbr_fd.c src/ft_star_process.c src/ft_to_hex.c src/ft_zeros_spaces.c ft_printf.c\
		arg_finder.c command_spliter.c length.c parser.c pipe_spliter.c sequencer.c add_part.c ft_split.c ft_substr.c equals.c free_parts.c

INC = -I ft_printf.h -I parser.h

all:$(NAME)

$(NAME):
	@$(CC) $(SRCS) $(INC)
clean:
	@rm -rf $(OBJ)
fclean:clean
	@rm -rf $(NAME)
re:fclean all
test:all clean
.PHONY: all clean fclean re