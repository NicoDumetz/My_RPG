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
    #include "level.h"
    #include "info_bar.h"
    #include "object.h"
    #include "effect.h"
    #include "player.h"
    #include "background.h"
    #include <time.h>
    #include <math.h>
    #include "biome.h"
    #include "collisions.h"
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
#endif
