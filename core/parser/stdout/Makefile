compile = gcc -Wall -Werror -Wextra -c
src = src/out.c src/outc.c
obj = out.o outc.o
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