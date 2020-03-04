/*
** EPITECH PROJECT, 2020
** parsing.c
** File description:
** source file fo parsing tools
*/

#include "../include/navy.h"

int error_size(char *pos, int i)
{
    int size = (pos[i] - 48);
    if (size == (pos[i + 5] - pos[i + 2] + 1)) {
        if (pos[i + 6] == pos[i + 3]) {
            return (1);
        } else {
            return 84;
        }
    } else {
        if (size == (pos[i + 6] - pos[i + 3] + 1)) {
            return (1);
        } else {
            return 84;
        }
    }
}


char *error_file(char *pos)
{
    int i = 0;
    int first = 50;
    while (i != 32) {
        if (pos[i] != first)
            return NULL;
        if (pos[i + 2] != pos[i + 5] && pos[i + 3] != pos[i + 6]) {
            return NULL;
        }
        if (error_size(pos, i) == 84) {
            return NULL;
        }
        i += 8;
        first += 1;
    }
    return pos;
}

char *parsing_file(char *filepath)
{
    int file_des;
    char *pos;
    if ((file_des = open(filepath, O_RDONLY)) < 0)
        return NULL;
    pos = malloc(sizeof(char) * READ_SIZE + 1);
    read(file_des, pos, READ_SIZE);
    if (read(file_des, pos, 1) != 0) {
        return NULL;
    }
    pos[READ_SIZE] = '\0';
    pos = error_file(pos);
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
    if (my_put_boats(pos, map) == 84) {
        return NULL;
    }
    return (map);
}