
NAME = core.a
makeParser = make -C parser/

OBJ =	parser/ft_abs.o parser/ft_finder.o parser/ft_mix_help.o parser/ft_nb_length.o parser/ft_processor.o parser/ft_putnbr_u_fd.o parser/ft_strchr.o parser/ft_type_len.o parser/star_help.o\
		parser/ft_atoi.o parser/ft_inits.o parser/ft_mix_help_2.o parser/ft_point_process.o parser/ft_putchar_fd.o parser/ft_putstr_fd.o parser/ft_strlen.o parser/ft_zero_process.o\
		parser/ft_char_times.o parser/ft_match_conversion.o parser/ft_mixed_flags.o parser/ft_print_type.o parser/ft_putnbr_fd.o parser/ft_star_process.o parser/ft_to_hex.o parser/ft_zeros_spaces.o parser/ft_printf.o\
		parser/arg_finder.o parser/command_spliter.o parser/length.o parser/parser.o parser/pipe_spliter.o parser/sequencer.o parser/add_part.o parser/get_path.o parser/ft_split.o parser/ft_substr.o parser/get_dir.o parser/equals.o
all:$(NAME)

$(NAME):
	@$(makeParser)
	@ar -rc $(NAME) $(OBJ)
	@rm -rf $(OBJ)
	@mv $(NAME) ../
clean:
	@rm -rf $(OBJ)

fclean:clean
	@rm -rf $(NAME)

re:fclean all

.PHONY: all clean fclean re