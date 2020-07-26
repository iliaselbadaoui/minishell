compile = gcc -Wall -Werror -Wextra
src = get_next_line.c get_next_line_utils.c  main.c

NAME = minishell
makeCore = make -C core/

all:$(NAME)

$(NAME):
	@$(makeCore)
	@$(compile) $(src) core.a -o $(NAME)
clean:
	@rm -rf core.a
fclean:clean
	@rm -rf $(NAME)
re:fclean all

.PHONY: all clean fclean re