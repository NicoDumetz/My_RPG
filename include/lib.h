/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** macro for CSFML
*/

#ifndef LIB_H
    #define LIB_H
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <errno.h>
    #include <dirent.h>
    #include "quest.h"
    #include "button.h"
    #include "level.h"
    #include "save.h"
    #include "info_bar.h"
    #include "object.h"
    #include "effect.h"
    #include "skill.h"
    #include "player.h"
    #include "background.h"
    #include <time.h>
    #include <math.h>
    #include "projectile.h"
    #include "biome.h"
    #include "collisions.h"
    #include "inventory.h"
    #include "tuto.h"
    #include "particule.h"
    #include "song.h"
    #define ABS(x) ((x) < 0 ? x = -(x) : (x))
    #define TWA "assets/tiny_world_asset/"
    #define PARAM_ASS "assets/param_asset/"
    #define KNIGHT_ASSET "assets/tiny_world_asset/Factions/Knights/Troops/"
    #define GOBLINS_ASSET "assets/tiny_world_asset/Factions/Goblins/Troops/"
    #define KNIGHT_SPRITE KNIGHT_ASSET "Warrior/Blue/Warrior_Blue.png"
    #define ARCHER_SPRITE KNIGHT_ASSET "Archer/Blue/Archer_Blue.png"
    #define MINIONS_SPRITE KNIGHT_ASSET "Pawn/Blue/Pawn_Blue.png"
    #define GOBLINS_T_SPRITE GOBLINS_ASSET "Torch/Red/Torch_Red.png"
    #define GOBLINS_B_SPRITE GOBLINS_ASSET "Barrel/Red/Barrel_Red.png"
    #define GOBLINS_D_SPRITE GOBLINS_ASSET "TNT/Red/TNT_Red.png"
    #define PLAINE_SPRITE "assets/biome_asset/Plaine.png"
    #define PLAINE_COLISION "assets/biome_asset/col_plaine.png"
    #define MINE_SPRITE "assets/biome_asset/map_mine.png"
    #define MINE_COLISION "assets/biome_asset/FonNoiMine.png"
    #define CAMP_SPRITE "assets/biome_asset/Map_foret.png"
    #define CAMP_COLISION "assets/biome_asset/FondNoirfo.png"
    #define VILLAGE_SPRITE "assets/biome_asset/Plaine.png"
    #define VILLAGE_COLISION "assets/biome_asset/col_plaine.png"
    #define CASTLE_SPRITE "assets/biome_asset/chateau.png"
    #define CASTLE_COLISION "assets/biome_asset/col_chateau.png"
    #define DEATH_PATH TWA "Factions/Knights/Troops/Dead/Dead.png"
    #define KNIGHT_BUILDINGS TWA "Factions/Knights/Buildings/"
    #define TREE_SPRITE "assets/tiny_world_asset/Resources/Trees/Tree.png"
    #define KNIGHT_H_SPRITE KNIGHT_BUILDINGS "House/House_Blue.png"
    #define MINE_S TWA "Resources/Gold Mine/GoldMine_Active.png"
    #define BAG_PATH "assets/tiny_world_asset/Resources/Resources/G_Spawn.png"
    #define BLOOD_PATH "assets/effect_asset/blood_effect.png"
    #define COIN_PATH "assets/effect_asset/coin.png"
    #define LEVEL_UP_PATH "assets/effect_asset/level_up.png"
    #define BACK_SAVE_PATH "assets/save_asset/back_save.png"
    #define FOOTER_SAVE_PATH "assets/save_asset/footer_save.png"
    #define HEADER_SAVE_PATH "assets/save_asset/header_save.png"
    #define EXIT_BUTTON_PRESS TWA "UI/Icons/Pressed_01.png"
    #define EXIT_BUTTON_RELEASED TWA "UI/Icons/Regular_01.png"
    #define BLUE_LONG_PRESS TWA "UI/Buttons/Blue_long_pressed.png"
    #define BLUE_LONG_REL TWA "UI/Buttons/Blue_long_released.png"
    #define HOVER_LONG_BUT TWA "UI/Buttons/Button_long_hover.png"
    #define PIXEL_F_PATH "assets/font/pixel_font.ttf"
    #define LIFE_BAR_PATH "assets/info_bar_asset/BarreDeVie.png"
    #define ENERGY_BAR_PATH "assets/info_bar_asset/Energie.png"
    #define XP_BAR_PATH "assets/info_bar_asset/Niveau.png"
    #define PLAY "assets/menu_asset/button_play.png"
    #define PLAY_PRESSED "assets/menu_asset/button_play_pressed.png"
    #define PLAY_HOVER "assets/menu_asset/button_play_hover.png"
    #define B_SAVE "assets/menu_asset/button_save.png"
    #define B_SAVE_HOVER "assets/menu_asset/button_save_hover.png"
    #define B_SAVE_PRESSED "assets/menu_asset/button_save_pressed.png"
    #define B_SAVE_BLOCK "assets/menu_asset/button_save_block.png"
    #define B_NSAVE "assets/menu_asset/button_nsave.png"
    #define B_NSAVE_HOVER "assets/menu_asset/button_nsave_hover.png"
    #define B_NSAVE_PRESSED "assets/menu_asset/button_nsave_pressed.png"
    #define B_NSAVE_BLOCK "assets/menu_asset/button_nsave_block.png"
    #define NEW "assets/menu_asset/button_new.png"
    #define NEW_HOVER "assets/menu_asset/button_new_hover.png"
    #define NEW_PRESSED "assets/menu_asset/button_new_pressed.png"
    #define PARAM "assets/menu_asset/button_param.png"
    #define PARAM_PRESSED "assets/menu_asset/button_param_pressed.png"
    #define PARAM_HOVER "assets/menu_asset/button_param_hover.png"
    #define QUIT "assets/menu_asset/button_quit.png"
    #define QUIT_PRESSED "assets/menu_asset/button_quit_pressed.png"
    #define QUIT_HOVER "assets/menu_asset/button_quit_hover.png"
    #define BACK_PARAM "assets/param_asset/background.png"
    #define PAGE_PARAM "assets/param_asset/page.png"
    #define RIBBONS_PARAM "assets/param_asset/ribbons_param.png"
    #define RIBBONS_PARAM_PRESSED PARAM_ASS "ribbons_param_pressed.png"
    #define BUTTON_WINDOW "assets/param_asset/button_window.png"
    #define BUTTON_WINDOW_PRESSED PARAM_ASS "button_window_pressed.png"
    #define BUTTON_FULL "assets/param_asset/button_fullscreen.png"
    #define BUTTON_FULL_PRESSED PARAM_ASS "button_fullscreen_pressed.png"
    #define BUTTON_1920x1080 "assets/param_asset/1920*1080.png"
    #define BUTTON_1280x720 "assets/param_asset/1280*720.png"
    #define BUTTON_850x480 "assets/param_asset/850*480.png"
    #define RES_SELECTION "assets/param_asset/selection.png"
    #define BUTTON_SOUND "assets/param_asset/button_sound.png"
    #define BUTTON_SOUND_PRESSED "assets/param_asset/button_sound_pressed.png"
    #define BUTTON_PLUS "assets/param_asset/button_plus.png"
    #define BUTTON_PLUS_PRESSED "assets/param_asset/button_plus_pressed.png"
    #define BUTTON_MINUS "assets/param_asset/button_minus.png"
    #define BUTTON_MINUS_PRESSED "assets/param_asset/button_minus_pressed.png"
    #define MENU_INGAME "assets/menu_asset/menu_ingame.png"
    #define RESUME "assets/menu_asset/button_resume.png"
    #define RESUME_PRESSED "assets/menu_asset/button_resume_pressed.png"
    #define RESUME_HOVER "assets/menu_asset/button_resume_hover.png"
    #define VINQUE "assets/font/gothicrpgfont.ttf"
    #define CAMP_BOSS_PATH "assets/boss_asset/Torch_Purple.png"
    #define MINE_BOSS_PATH "assets/boss_asset/TNT_Yellow.png"
    #define CASTLE_BOSS_PATH "assets/boss_asset/Warrior_Purple.png"
    #define ARROWS TWA "Factions/Knights/Troops/Archer/Arrow.png"
    #define DYNAMITE TWA "Factions/Goblins/Troops/TNT/Dyna.png"
    #define ARENE_PATH "assets/biome_asset/Arène.png"
    #define ARENE_COL_PATH "assets/biome_asset/FondArene.png"
    #define EXPLO_PATH TWA "Effects/Explosion/Explosions.png"
    #define SHIELD_PATH "assets/effect_asset/shield.png"
    #define FIRE_PATH "assets/tiny_world_asset/Effects/Fire/fireball.png"
    #define CURSOR_PATH "assets/tiny_world_asset/cursor.png"
    #define MENU_1_PATH "assets/menu_asset/menu1.png"
    #define MENU_2_PATH "assets/menu_asset/menu2.png"
    #define MENU_3_PATH "assets/menu_asset/menu3.png"
    #define MENU_4_PATH "assets/menu_asset/menu4.png"
    #define MENU_5_PATH "assets/menu_asset/menu5.png"
    #define MENU_6_PATH "assets/menu_asset/menu6.png"
    #define MENU_7_PATH "assets/menu_asset/menu7.png"
    #define MENU_8_PATH "assets/menu_asset/menu8.png"
#endif
