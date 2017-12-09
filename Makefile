NAME		=	resources/players/scollet.filler
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra -I includes
LIBRARY		=	libft
LIBRARY_B	=	libft/build
LIB_A		=	libft.a
FILES		=	main.c error.c parse.c init.c play.c

SOURCES		=	$(addprefix src/, $(FILES))
OBJECTS		=	$(addprefix build/, $(FILES:.c=.o))

.PHONY: clean fclean all re

all:	$(NAME)

clean:
	@rm -rf build
	@rm -rf $(LIBRARY_B)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIB_A)

re: fclean all

$(NAME): $(OBJECTS)
	@make -C $(LIBRARY)
	@$(CC) -o $@ $(FLAGS) $(OBJECTS) -L $(LIBRARY) -lft -fsanitize=address

build:
	@mkdir build/

build/%.o: src/%.c | build
	@$(CC) $(FLAGS) -c $< -o $@
