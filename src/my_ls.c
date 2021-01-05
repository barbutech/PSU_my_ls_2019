/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls.c
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/structures.h"
#include "../include/my.h"
#include <errno.h>

setup_t *create_settings(int ac, char **av)
{
    setup_t *settings = malloc(sizeof(setup_t));

    settings->ac = ac;
    settings->av = av;
    settings->nbr_of_files = 0;
    return (settings);
}

int print_ls(setup_t *settings, flags_t *flags_available)
{   int size = 1;

    if (settings->nbr_of_files == 1)
        case_of_one(settings, flags_available, size);
    for (; size < settings->ac;size++){
        error_and_dirmanagement(&settings, size);
        if (errno == EACCES)
            return (84);
        if (settings->fd != NULL) {
            settings->file = readdir(settings->fd);
            case_of_folder(settings, flags_available, size);
        }
        else if (settings->fd == NULL && errno != ENOENT) {
            flag_L(settings, flags_available, size);
            my_putstr(settings->av[size]);
            write(1, "\n", 1);
            if (size < flags_available->last_arg)
                write(1, "\n", 1);
            else
                return (0);
        } else if (settings->av[size][0] != '-')
            return (84);
    }
}

int simple_ls(setup_t *settings, flags_t *flags_available)
{
    for (int tmp = 0; tmp < settings->ac ; tmp++)
        if (settings->av[tmp][0] != '-')
            settings->nbr_of_files++;
    if (print_ls(settings, flags_available) == 84)
        return (84);
    return (0);
}

int main(int argc, char *argv[])
{
    flags_t *flags_available = malloc(sizeof(flags_t));
    setup_t *settings = create_settings(argc, argv);

    flags_available->d = 0;
    flags_available->t = 0;
    flags_available->l = 0;
    flags_available->R = 0;
    flags_available->r = 0;
    flags_available = parse(argc, argv, flags_available);
    if (simple_ls(settings, flags_available) == 84)
        return (84);
    closedir(settings->fd);
    return 0;
}
