##
## EPITECH PROJECT, 2024
## B-MUL-200-LIL-2-1-mypaint-matisse.dufour
## File description:
## new_Makefile
##

SRC = main.c\
	src/main_loop.c\
	src/event/manage_event.c\
	src/buttons/create_buttons.c\
	src/buttons/init_buttons.c\
	src/buttons/update_button.c\
	src/tools/destroy_sprite.c\
	src/tools/my_strncmp.c\
	src/tools/my_strlen.c\
	src/tools/my_putstr.c\
	src/init_rpg_struct.c\


OBJ = $(SRC:.c=.o)

NAME = my_rpg

CFLAGS += -Wall -Wextra -g \
		  -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm \
		  -I ./include

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)
	rm -f $(OBJ)

re: fclean all
