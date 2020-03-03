/*
** EPITECH PROJECT, 2020
** boats.c
** File description:
** source file to handle boats
*/

#include "../include/navy.h"

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