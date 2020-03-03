/*
** EPITECH PROJECT, 2020
** navy.c
** File description:
** main source file for navy project
*/

#include "../include/navy.h"

void connection(player_t *player, int play)
{
    if (play == 1) {
        my_putstr("waiting for enemy connection...\n");
    }
    usleep(2000);
}

int navy_player_one(player_t *player)
{
    display_pid(player->my_pid);
    connection(player, 1);
    //display_map(player->map);
    return (0);
}

int navy_player_two(player_t *player)
{
    display_pid(player->my_pid);
    connection(player, 2);
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
            return (84);
        if (navy_player_one(&player) == 84)
            return (84);
    } else {
        if (my_init_player_two(&player, av) == 84)
            return (84);
        if (navy_player_two(&player) == 84)
            return (84);
    }
    return (0);
}
