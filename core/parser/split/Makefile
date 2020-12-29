compile = gcc -Wall -Werror -Wextra -c
srcs = src/create_grid.c src/fill_grid.c src/ft_split.c src/ft_count.c
objs = create_grid.o fill_grid.o ft_count.o ft_split.o ft_count.o
header = ../ft_split.h
NAME = ft_split.a

$(NAME) : all

all :
	@$(compile) $(srcs) -I $(header)
	@ar -rc $(NAME) $(objs)
clean :
	@rm -rf $(objs)
fclean : clean
	@rm -rf $(NAME)
re : fclean all

.PHONY : all clean fclean re