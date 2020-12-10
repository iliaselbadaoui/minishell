compile = gcc -Wall -Werror -Wextra -c
src = src/out.c
obj = out.o
NAME = out.a
lib = out.h

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