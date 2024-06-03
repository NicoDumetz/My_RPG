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
    #include "player.h"
    #include "background.h"
    #include <time.h>
    #include <math.h>
    #include "biome.h"
    #include "collisions.h"
    #include "tuto.h"
    #define ABS(x) ((x) < 0 ? x = -(x) : (x))
    #define KNIGHT_ASSET "tiny_world_asset/Factions/Knights/Troops/"
    #define GOBLINS_ASSET "tiny_world_asset/Factions/Goblins/Troops/"
    #define KNIGHT_SPRITE KNIGHT_ASSET "Warrior/Blue/Warrior_Blue.png"
    #define ARCHER_SPRITE KNIGHT_ASSET "Archer/Blue/Archer_Blue.png"
    #define MINIONS_SPRITE KNIGHT_ASSET "Pawn/Blue/Pawn_Blue.png"
    #define GOBLINS_T_SPRITE GOBLINS_ASSET "Torch/Red/Torch_Red.png"
    #define GOBLINS_B_SPRITE GOBLINS_ASSET "Barrel/Red/Barrel_Red.png"
    #define GOBLINS_D_SPRITE GOBLINS_ASSET "TNT/Red/TNT_Red.png"
    #define PLAINE_SPRITE "biome_asset/Plaine.png"
    #define PLAINE_COLISION "biome_asset/col_plaine.png"
    #define MINE_SPRITE "biome_asset/map_mine.png"
    #define MINE_COLISION "biome_asset/FonNoiMine.png"
    #define CAMP_SPRITE "biome_asset/Map_foret.png"
    #define CAMP_COLISION "biome_asset/FondNoirfo.png"
    #define VILLAGE_SPRITE "biome_asset/Plaine.png"
    #define VILLAGE_COLISION "biome_asset/col_plaine.png"
    #define CASTLE_SPRITE "biome_asset/chateau.png"
    #define CASTLE_COLISION "biome_asset/col_chateau.png"
    #define DEATH_PATH "tiny_world_asset/Factions/Knights/Troops/Dead/Dead.png"
    #define KNIGHT_BUILDINGS "tiny_world_asset/Factions/Knights/Buildings/"
    #define TREE_SPRITE "tiny_world_asset/Resources/Trees/Tree.png"
    #define KNIGHT_H_SPRITE KNIGHT_BUILDINGS "House/House_Blue.png"
    #define MINE_S "tiny_world_asset/Resources/Gold Mine/GoldMine_Active.png"
    #define BAG_PATH "tiny_world_asset/Resources/Resources/G_Spawn.png"
    #define BLOOD_PATH "effect_asset/blood_effect.png"
    #define COIN_PATH "effect_asset/coin.png"
    #define LEVEL_UP_PATH "effect_asset/level_up.png"
    #define BACK_SAVE_PATH "save_asset/back_save.png"
    #define FOOTER_SAVE_PATH "save_asset/footer_save.png"
    #define HEADER_SAVE_PATH "save_asset/header_save.png"
    #define EXIT_BUTTON_PRESS "tiny_world_asset/UI/Icons/Pressed_01.png"
    #define EXIT_BUTTON_RELEASED "tiny_world_asset/UI/Icons/Regular_01.png"
    #define BLUE_LONG_PRESS "tiny_world_asset/UI/Buttons/Blue_long_pressed.png"
    #define BLUE_LONG_REL "tiny_world_asset/UI/Buttons/Blue_long_released.png"
    #define HOVER_LONG_BUT "tiny_world_asset/UI/Buttons/Button_long_hover.png"
    #define PIXEL_F_PATH "font/pixel_font.ttf"
    #define LIFE_BAR_PATH "info_bar_asset/BarreDeVie.png"
    #define ENERGY_BAR_PATH "info_bar_asset/Energie.png"
    #define XP_BAR_PATH "info_bar_asset/Niveau.png"
    #define CAMP_BOSS_PATH "boss_asset/Torch_Purple.png"
    #define MINE_BOSS_PATH "boss_asset/TNT_Yellow.png"
    #define CASTLE_BOSS_PATH "boss_asset/Warrior_Purple.png"
    #define ARENE_PATH "biome_asset/Arène.png"
    #define ARENE_COL_PATH "biome_asset/FondArene.png"
#endif
