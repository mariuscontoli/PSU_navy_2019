/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main source file for navy project
*/

#include "../include/navy.h"

int my_navy(player_t *player)
{
    display_pid(player->my_pid);
    display_map(player->map);
    return (0);
}

int main(int ac, char **av)
{
    player_t player;

    if (ac != 2 && ac != 3) {
        return (84);
    }
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            display_help();
            return (0);
        }
        if (my_init_player_one(&player, av) == 84)
            return 84;
        my_navy(&player);
    } else {
        if (my_init_player_two(&player, av) == 84)
            return 84;
        my_navy(&player);
    }
    return (0);
}
