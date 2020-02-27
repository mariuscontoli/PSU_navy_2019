/*
** EPITECH PROJECT, 2020
** navy.h
** File description:
** navy header file 
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

enum play_state {
    PLAYER_ONE,
    PLAYER_TWO
};

typedef struct map {
    char **map;
    int map_size;
} map_t;

typedef struct navy {
    int pid_host;
    int pid_guest;
    map_t map;
} navy_t;

//UTILS
int my_strlen(char *str);

#endif /* !NAVY_H_ */
