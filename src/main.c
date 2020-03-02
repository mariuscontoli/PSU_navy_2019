/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main source file for navy project
*/

#include "../include/navy.h"

void display_map(char **tab)
{
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

int my_put_boats(char *pos, char **map)
{
    int i = 0;
    int x1, x2, y1, y2 = 0;
    while (pos[i] != '\0') {
        x1 = pos[i + 2] - 65;
        y1 = pos[i + 3] - 49;
        x2 = pos[i + 5] - 65;
        y2 = pos[i + 6] - 49;
        while (y1 <= y2 && x1 <= x2) {
            while (x1 < x2) {
                if (map[y1][x1] == '.') {
                    map[y1][x1] = pos[i];
                    x1++;
                } else
                    return 84;
            }
            if (map[y1][x1] == '.') {
                map[y1][x1] = pos[i];
                y1++;
            } else
                return 84;
        }
        i += 8;
    }
    return (0);
}

void display_pid(int pid)
{
    if (pid == 0) {
        int process = getpid();
        my_printf("my_pid: %d\n", process);
    } else {
        my_printf("my_pid: %d\n", pid);
    }
}

char *parsing_file(char *filepath)
{
    int file_des;
    char *pos;
    file_des = open(filepath, O_RDONLY);
    pos = malloc(sizeof(char) * READ_SIZE + 1);
    read(file_des, pos, READ_SIZE);
    pos[READ_SIZE] = '\0';
    return (pos);
}

char **parsing_map(char *filepath)
{
    char **map;
    char *pos;
    int i = 0;
    pos = parsing_file(filepath);
    if (pos == NULL)
        return NULL;
    map = malloc(sizeof(char*) * MAP_SIZE + 1);
    map[MAP_SIZE] = NULL;
    while (i <= MAP_SIZE - 1) {
        map[i] = my_strdup("........");
        i++;
    }
    printf("POS :\n%s\n", pos);
    my_put_boats(pos, map);
    return (map);
}

int my_navy(player_t *player)
{
    display_pid(player->my_pid);
    display_map(player->map);
    return (0);
}

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
    while (i <= MAP_SIZE - 1 ) {
        player->enemy_map[i] = my_strdup("........");
        i++;
    }
    player->my_pid = getpid();
    player->his_pid = 0;
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
        my_init_player_one(&player, av);
        my_navy(&player);
    } else {
        my_init_player_two(&player, av);
        my_navy(&player);
    }
    return (0);
}
