compile = gcc -Wall -Werror -Wextra -c
src = src/in.c src/in_utils.c
obj = in.o in_utils.o
NAME = in.a
lib = in.h

all: $(NAME)

$(NAME):
	@$(compile) $(src) -I $(lib)
	@ar -rc $(NAME) $(obj)
clean:
	@rm -rf $(obj)
fclean: clean
	@rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re