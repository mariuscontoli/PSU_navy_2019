/*
** EPITECH PROJECT, 2020
** display.c
** File description:
** source file to display map and pid
*/

#include "../include/navy.h"

void display_pid(int pid)
{
    if (pid == 0) {
        int process = getpid();
        my_printf("my_pid: %d\n", process);
    } else {
        my_printf("my_pid: %d\n", pid);
    }
}

void display_my_map(char **tab)
{
    my_putstr("\n");
    my_putstr("my positions:\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; tab[i] != NULL; i++) {
        my_printf("%d|", i + 1);
        for (int z = 0; tab[i][z] != '\0'; z++) {
            if (z > 0)
                my_putchar(' ');
            my_putchar(tab[i][z]);
        }
        my_printf("\n");
    }
}

void display_enemy_map(char **tab)
{
    my_putstr("\n");
    my_putstr("enemy's positions:\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; tab[i] != NULL; i++) {
        my_printf("%d|", i + 1);
        for (int z = 0; tab[i][z] != '\0'; z++) {
            if (z > 0)
                my_putchar(' ');
            my_putchar(tab[i][z]);
        }
        my_printf("\n");
    }
}