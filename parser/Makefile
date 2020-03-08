cc = gcc -Wall -Wextra -Werror -c
NAME = parser.a
inc = -I parser.h -I ../types.h
srcs = parser/contains.c parser/equals.c parser/line_parser.c
objs = contains.o equals.o line_parser.o
all: $(NAME)

$(NAME):
	@$(cc) $(srcs) $(inc)
	@ar rc $(NAME) $(objs)
clean:
	@rm -rf *.o
fclean: clean
	@rm -rf $(NAME)