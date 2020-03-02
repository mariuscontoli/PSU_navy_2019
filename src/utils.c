/*
** EPITECH PROJECT, 2020
** utils.c
** File description:
** utilitary fucntions source file
*/

#include "../include/navy.h"

char *my_strdup(char const *src)
{
    char *str;
    int copy = 0;
    int size = 0;
    size = my_strlen(src);
    str = malloc(size);
    while (src[copy] != '\0') {
        str[copy] = src[copy];
        copy++;
    }
    str[copy] = '\0';
    return (str);
}