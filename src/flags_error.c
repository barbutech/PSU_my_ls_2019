/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** flags_error.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include "../include/structures.h"
#include "../include/my.h"
#include <errno.h>

flags_t *parse(int argc, char **argv, flags_t *flags_available)
{
    char *flags = "\0";
    int size_flags = 0;

    for (int count = 0; count < argc; count++)
        if (argv[count][0] == '-') {
            flags = my_str_allocate_and_cat(flags, argv[count]);
            size_flags = my_strlen(flags);
        } else
            flags_available->last_arg = count;
    for (int size_tempo = 0; size_tempo < size_flags; size_tempo++) {
        (flags[size_tempo] == 'd')? flags_available->d = 1 : 0;
        (flags[size_tempo] == 't')? flags_available->t = 1 : 0;
        (flags[size_tempo] == 'l')? flags_available->l = 1 : 0;
        (flags[size_tempo] == 'R')? flags_available->R = 1 : 0;
        (flags[size_tempo] == 'r')? flags_available->r = 1 : 0;
    }
    return (flags_available);
}

void flag_L(setup_t *settings, flags_t *flags_available, int size)
{
    struct stat file_stat;
    char *arg;
    char *name;

    if (flags_available->l != 1)
        return;
    if (settings->fd != NULL) {
        arg = my_str_allocate_and_cat(settings->av[size], "/");
        name = my_str_allocate_and_cat(arg, settings->file->d_name);
        if (settings->nbr_of_files != 1)
            lstat(name, &file_stat);
        else
        lstat(settings->file->d_name, &file_stat);
    }
    else
        lstat(settings->av[size], &file_stat);
    type_arg(file_stat);
    rights_arg(file_stat);
    my_put_nbr(file_stat.st_nlink);
    print_name_and_group(file_stat);
    time_param(file_stat);
}

int flag_d(setup_t *settings)
{
    if (settings->nbr_of_files == 1) {
        my_putstr(".\n");
        return (0);
    }
    for (int tmp = 1; tmp < settings->ac; tmp++) {
        if (settings->av[tmp][0] != '-') {
            my_putstr(settings->av[tmp]);
            write(1, "\n", 1);
        }
    }
    return (0);
}

void error_and_dirmanagement(setup_t **settings, int size)
{
    if ((*settings)->nbr_of_files == 1)
        (*settings)->fd = opendir(".");
    else if ((*settings)->nbr_of_files == 2)
        (*settings)->fd = opendir((*settings)->av[size]);
    else {
        (*settings)->fd = opendir((*settings)->av[size]);
        if ((*settings)->fd != NULL) {
            my_putstr((*settings)->av[size]);
            write(1, ":\n", 2);
        }
    }
}