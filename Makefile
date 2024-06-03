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
	src/animations/anim_obj_long.c\
	src/entity/bot/set_bot_effect.c\
	src/portal/create_portal.c\
	src/tools/rect_is_in_circleshape.c\
	src/biome/switch_biome.c\
	src/entity/info_bar.c/create_info_bar.c\
	src/entity/heros/manage_heros_bar.c\
	src/entity/heros/level_tab.c\
	src/entity/info_bar.c/update_info_bar.c\
	src/tools/convert_int_to_str.c\
	src/save/write_data_in_save.c\
	src/save/update_save_list.c\
	src/save/create_save.c\
	src/save/create_file_list.c\
	src/tools/mouse_pos_relative_to_view.c\
	src/save/save_scene.c\
	src/set_all_font.c\
	src/save/init_load_page.c\
	src/save/exit_button_released.c\
	src/save/save_button_released.c\
	src/save/remake_bot_list.c\
	src/quest/init_quest.c\
	src/quest/quest_displayer.c\
	src/entity/quest_giver/init_quest_giver.c\
	src/entity/quest_giver/manage_quest_giver.c\
	src/entity/quest_giver/next_quest.c\
	src/save/appli_save_quest.c\
	src/inventory/init_inventory.c\
	src/inventory/inventory.c\
	src/inventory/slots/init_slots.c\
	src/inventory/slots/set_slots.c\
	src/entity/bot/ia/attack_bot.c\
	src/portal/check_open_portal.c\
	src/quest/check_end_quest.c\
	src/tuto/init_quest_giver_tuto.c\
	src/tuto/create_tuto.c\
	src/tuto/tuto_loop.c\
	src/tuto/skip_released.c\
	src/tuto/manage_skip_button.c\
	src/tuto/init_quest_tuto.c\
	src/tuto/quest/move_quest.c\
	src/tuto/quest/manage_quest_tuto.c\
	src/tuto/quest/check_if_pressed_touch.c\
	src/tuto/quest/start_test_t.c\
	src/attack/projectile/manage_projectile.c\
	src/attack/projectile/init_pro_bot.c\
	src/skill/init_fire_ball.c\
	src/skill/init_shield.c\
	src/skill/init_run.c\
	src/skill/init_skill.c\
	src/skill/manage_skill.c\
	src/biome/set_bot_donjon.c\

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
