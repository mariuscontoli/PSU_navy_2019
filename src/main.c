/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main source file for navy project
*/

#include "../include/navy.h"

int check_errors(int ac, char **av)
{
    if (ac > 3) {
        return (84);
    }
    return (0);
}

int find_map(char *filepath)
{
    navy_t *navy = malloc(sizeof(*navy));
    struct stat off_t;
    int fd = open(filepath, O_RDONLY);
    stat(filepath, &off_t);
    navy->map.map_size = off_t.st_size;
    if (fd < 0 || navy->map.map_size < 0) {
        return (84);
    }
    navy->map.map = malloc(sizeof(char) * (off_t.st_size + 1));
    read(fd, navy->map.map, off_t.st_size);
    return (0);
}

int main(int ac, char **av)
{
    if (check_errors(ac, av) == 84) {
        return (84);
    }
    if (ac == 1) {
        if (find_map(av[1] == 84)) {
            return (84);
        }
    }
    run();
    return (0);
}
