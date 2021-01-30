MakeDir = make
compile = gcc -Wall -Werror -Wextra  -c
src = src/*.c
obj = *.o
NAME = executer.a
lib = executer.h

all: $(NAME)

$(NAME):
	@$(compile) $(src) -I $(lib)
	@ar -rc $(NAME) $(obj)
clean:
	# @$(MakeDir) clean -C stdout/
	# @$(MakeDir) clean -C stdin/
	# @$(MakeDir) clean -C split/
	@rm -rf $(obj)
fclean: clean
	# @$(MakeDir) fclean -C stdout/
	# @$(MakeDir) fclean -C stdin/
	# @$(MakeDir) fclean -C split/
	@rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re