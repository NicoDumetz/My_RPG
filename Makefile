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
	src/tools/create_sprite.c\
	src/tools/my_strlen.c\
	src/tools/my_putstr.c\
	src/entity/heros/init_heros.c\
	src/entity/npc/init_npc.c\
	src/entity/init_entity.c\
	src/entity/set_hitbox.c\
	src/entity/set_offset.c\
	src/entity/bot/init_bot_data.c\
	src/entity/bot/set_minions.c\
	src/entity/bot/set_goblins.c\
	src/entity/bot/set_goblins_b.c\
	src/entity/bot/set_goblins_d.c\
	src/entity/bot/set_knight.c\
	src/entity/bot/set_archer.c\
	src/entity/bot/create_bot.c\
	src/animations/anim_entity.c\
	src/init_rpg_struct.c\
	src/test.c\
	src/background/init_background.c\
	src/movements/movements.c\
	src/event/manage_key/manage_down.c\
	src/event/manage_key/manage_up.c\
	src/event/manage_key/manage_left.c\
	src/event/manage_key/manage_right.c\

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
