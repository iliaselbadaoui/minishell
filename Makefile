MakeDir = make
compile = gcc -Wall -Werror -Wextra
NAME = minishell
src = main.c
headers = -Icore/parser/parser.h -Icore/executer/executer.h
# core/executer/executer.a => add this WHEN A FUNCTION WITHIN EXECUTER IS DONE
libs = core/parser/parser.a core/parser/stdout/out.a core/parser/stdin/in.a core/parser/split/ft_split.a
all: $(NAME)
	
$(NAME):
	@# UNCOMMENT ONLY WHEN A FUNCTION WITHIN EXECUTER IS DONE
	@# @$(MakeDir) -C core/executer/
	@$(MakeDir) -C core/parser/
	@$(compile) $(src) -I $(headers) $(libs) -o $(NAME)
clean:
	# @$(MakeDir) clean -C core/executer/
	@$(MakeDir) clean -C core/parser/
fclean: clean
	# @$(MakeDir) fclean -C core/executer/
	@$(MakeDir) fclean -C core/parser/
	@rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re