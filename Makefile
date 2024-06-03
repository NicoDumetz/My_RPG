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
	src/biome/biome_loop.c\
	src/background/init_background.c\
	src/movements/movements.c\
	src/event/manage_key/manage_down.c\
	src/event/manage_key/manage_up.c\
	src/event/manage_key/manage_left.c\
	src/event/manage_key/manage_right.c\
	src/attack/heros/manage_heros_attack.c\
	src/biome/init_biome.c\
	src/biome/set_castle.c\
	src/biome/set_plain.c\
	src/biome/set_mine.c\
	src/biome/set_village.c\
	src/biome/set_camp.c\
	src/entity/deco/init_deco_data.c\
	src/entity/deco/create_knight_house.c\
	src/entity/deco/display_deco.c\
	src/collisions/static_collisions.c\
	src/collisions/hit_collisions.c\
	src/animations/anim_attack.c\
	src/collisions/put_black_rect_on_col.c\
	src/entity_manager/sort_entity_in_view.c\
	src/entity_manager/put_entity_in_view_list.c\
	src/tools/sprite_is_in_float_rect.c\
	src/entity_manager/entity_loop.c\
	src/entity/heros/manage_heros.c\
	src/entity/bot/ia/manage_bot.c\
	src/entity/bot/bot_generator.c\
	src/collisions/check_dynamic_collided.c\
	src/entity/bot/ia/check_if_heros_attack_me.c\
	src/entity/bot/ia/check_chase_heros.c\
	src/effect/init_effect.c\
	src/set_all_texture.c\
	src/animations/anim_effect_long.c\
	src/animations/anim_effect_short.c\
	src/object/create_object.c\
	src/object/obj_tab.c\
	src/animations/anim_obj_short.c\
	src/object/manage_obj.c\
	src/entity/bot/ia/random_moov.c\
	src/entity/bot/ia/chase.c\

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
