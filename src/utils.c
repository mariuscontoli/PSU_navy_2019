/*
** EPITECH PROJECT, 2020
** utils.c
** File description:
** utilitary fucntions source file
*/

#include "../include/navy.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

int my_strlen(char *str)
{
    int len;

    while (str[len] != '\0') {
        len++;
    }
    return len;
}