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

#define  _POSIX_C_SOURCE 200809L

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <signal.h>
#include "../my_printf/include/my_printf.h"

typedef struct player {
    char **map;
    char **enemy_map;
    int my_pid;
    int his_pid;
    int win_cond;
} player_t;

typedef struct navy {
    int pid_host;
    int pid_guest;
} navy_t;

int PID;

char **parsing_map(char *filepath);
char *parsing_file(char *filepath);
char *error_file(char *pos);
int my_init_player_one(player_t *player, char **av);
int my_init_player_two(player_t *player, char **av);
int navy_player_one(player_t *player);
int navy_player_two(player_t *player);
int play_game_one(player_t *player, struct sigaction sa);
int play_game_two(player_t *player, struct sigaction sa);
void signal_handler(int signal, siginfo_t *info, void *blabla);
int connect_one(player_t *player, struct sigaction sa);
int connect_two(player_t *player, struct sigaction sa);
int my_put_boats(char *pos, char **map);
int error_size(char *pos, int i);
void display_my_map(char **tab);
void display_enemy_map(char **tab);
void display_pid(int pid);
void display_help(void);
char *my_strdup(char const *src);
int my_getnbr(char *str);

#endif /* !NAVY_H_ */
