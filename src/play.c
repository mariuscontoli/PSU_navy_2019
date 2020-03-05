/*
** EPITECH PROJECT, 2020
** play.c
** File description:
** source file to play
*/

#include "../include/navy.h"

int play_game_one(player_t *player, struct sigaction sa)
{
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    display_my_map(player->map);
    display_enemy_map(player->enemy_map);
    return (0);
}

int play_game_two(player_t *player, struct sigaction sa)
{

    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    display_my_map(player->map);
    display_enemy_map(player->enemy_map);
    return (0);
}