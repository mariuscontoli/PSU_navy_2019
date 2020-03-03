/*
** EPITECH PROJECT, 2020
** help.c
** File description:
** display help for navy project
*/

#include "../include/navy.h"

void display_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid: only for the 2nd player. pid of the first player.\n");
    my_putstr("\tnavy_positions: file representing the positions of the ships.\n");
}