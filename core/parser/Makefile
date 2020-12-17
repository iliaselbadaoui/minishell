MakeDir = make
compile = gcc -Wall -Werror -Wextra -c
src = src/*.c
obj = *.o
NAME = parser.a
lib = parser.h

all: $(NAME)

$(NAME):
	@$(MakeDir) -C stdout/
	@$(MakeDir) -C stdin/
	@$(compile) $(src) -I $(lib)
	@ar -rc $(NAME) $(obj)
clean:
	@$(MakeDir) clean -C stdout/
	@$(MakeDir) clean -C stdin/
	@rm -rf $(obj)
fclean: clean
	@$(MakeDir) fclean -C stdout/
	@$(MakeDir) fclean -C stdin/
	@rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re