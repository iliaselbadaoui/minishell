cc = gcc -Wall -Wextra -Werror -c
NAME = builtins.a
inc = 
srcs = 
objs = 
all: $(NAME)

$(NAME):
	@$(cc) $(srcs) $(inc)
	@ar rc $(NAME) $(objs)
clean:
	@rm -rf *.o
fclean: clean
	@rm -rf $(NAME)