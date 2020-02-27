/*
** EPITECH PROJECT, 2020
** utils.c
** File description:
** utilitary fucntions source file
*/

#include "../include/navy.h"

int my_strlen(char *str)
{
    int len;

    while (str[len] != '\0') {
        len++;
    }
    return len;
}