/*
** EPITECH PROJECT, 2020
** navy.h
** File description:
** navy header file 
*/

#ifndef NAVY_H_
#define NAVY_H_

#ifndef READ_SIZE
#define READ_SIZE (32)
#endif /* !READ_SIZE */

#ifndef MAP_SIZE
#define MAP_SIZE (8)
#endif /* !MAP_SIZE */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include "../my_printf/include/my_printf.h"

typedef struct player {
    char **map;
    char **enemy_map;
    int my_pid;
    int his_pid;
} player_t;

typedef struct navy {
    int pid_host;
    int pid_guest;
} navy_t;

//UTILS
void display_help(void);
char *my_strdup(char const *src);

#endif /* !NAVY_H_ */
