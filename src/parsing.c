/*
** EPITECH PROJECT, 2020
** parsing.c
** File description:
** source file fo parsing tools
*/

#include "../include/navy.h"

char *parsing_file(char *filepath)
{
    int file_des;
    char *pos;
    file_des = open(filepath, O_RDONLY);
    pos = malloc(sizeof(char) * READ_SIZE + 1);
    if (read(file_des, pos, READ_SIZE) == -1) {
        return NULL;
    }
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
    if (my_put_boats(pos, map) == 84) {
        return NULL;
    }
    return (map);
}