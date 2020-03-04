/*
** EPITECH PROJECT, 2020
** init.c
** File description:
** source file for initializing game
*/

#include "../include/navy.h"

int my_init_player_one(player_t *player, char **av)
{
    int i = 0;

    player->map = parsing_map(av[1]);
    if (player->map == NULL) {
        return (84);
    }
    player->enemy_map = malloc(sizeof(char*) * MAP_SIZE + 1);
    player->enemy_map[MAP_SIZE] = NULL;
    while (i <= MAP_SIZE - 1) {
        player->enemy_map[i] = my_strdup("........");
        i++;
    }
    player->my_pid = getpid();
    player->his_pid = 0;
    return (0);
}

int my_init_player_two(player_t *player, char **av)
{
    int i = 0;

    player->map = parsing_map(av[2]);
    if (player->map == NULL) {
        return (84);
    }
    player->enemy_map = malloc(sizeof(char*) * MAP_SIZE + 1);
    player->enemy_map[MAP_SIZE] = NULL;
    while (i <= MAP_SIZE - 1) {
        player->enemy_map[i] = my_strdup("........");
        i++;
    }
    player->my_pid = getpid();
    player->his_pid = my_getnbr(av[1]);
    return (0);
}