cc = gcc -Wall -Werror -Wextra
makeft = make -f libft/Makefile
makeparser = make -f parser/Makefile
srcs = main.c
INC = minishell.h
NAME = ./minishell
libs = parser.a libft.a
all: $(NAME)

$(NAME):
	@$(makeparser)
	@$(makeft)
	@$(CC) $(srcs) -I $(INC) $(libs)  -o $(NAME)
	@rm -rf *.o
clean:
	@rm -rf $(libs)
	@rm -rf *.o
fclean: clean
	@rm -rf $(NAME)
re: fclean all