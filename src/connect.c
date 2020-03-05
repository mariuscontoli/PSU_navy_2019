/*
** EPITECH PROJECT, 2020
** connect.c
** File description:
** soure file for connecting users
*/

#include "../include/navy.h"

int connect_one(player_t *player, struct sigaction sa)
{
    display_pid(player->my_pid);
    my_putstr("waiting for enemy connection...\n\n");
    sigaction(SIGUSR2, &sa, NULL);
    pause();
    return (0);
}

int connect_two(player_t *player, struct sigaction sa)
{
    if (kill(player->his_pid, SIGUSR2) == -1) {
        my_putstr("Error : please enter a valid PID\n");
        return (84);
    }
    display_pid(player->my_pid);
    my_putstr("sucessfully connected\n");
    return (0);
}