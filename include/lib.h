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
    #include <stdio.h>
    #include "player.h"
    #include "background.h"
    #include <stdbool.h>
    #include <biome.h>
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
    #define MINE_SPRITE "biome_asset/Plaine.png"
    #define MINE_COLISION "biome_asset/col_plaine.png"
    #define CAMP_SPRITE "biome_asset/Plaine.png"
    #define CAMP_COLISION "biome_asset/col_plaine.png"
    #define VILLAGE_SPRITE "biome_asset/Plaine.png"
    #define VILLAGE_COLISION "biome_asset/col_plaine.png"
    #define CASTLE_SPRITE "biome_asset/Plaine.png"
    #define CASTLE_COLISION "biome_asset/col_plaine.png"
#endif
