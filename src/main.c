/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main source file for navy project
*/

#include "../include/navy.h"

void display_map(navy_t *navy)
{
    write(1, navy->map.map, navy->map.map_size);
    write(1, "\n", 1);
}

void display_pid(char *pid)
{
    if (pid == NULL) {
        int process = getpid();
        printf("my_pid: %d\n", process);
    }
}

int parsing_map(navy_t *navy, char *filepath)
{
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

int my_navy(char *pid, char *filepath)
{
    navy_t *navy = malloc(sizeof(*navy));
    parsing_map(navy, filepath);
    display_pid(pid);
    display_map(navy);
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2 && ac != 3) {
        return (84);
    }
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            display_help();
            return (0);
        }
        my_navy(NULL, av[1]);
    } else {
        my_navy(av[1], av[2]);
    }
    return (0);
}
