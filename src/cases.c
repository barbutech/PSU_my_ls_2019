/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** cases.c
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/structures.h"
#include "../include/my.h"
#include <errno.h>

void case_of_folder(setup_t *settings, flags_t *flags_available, int size)
{
        for (; settings->file != NULL; settings->file = readdir(settings->fd))
            if (settings->file->d_name[0] != '.') {
                flag_L(settings, flags_available, size);
                my_putstr(settings->file->d_name);
                write(1, "\n", 1);
            }
            if (size < flags_available->last_arg)
                write(1, "\n", 1);
}

void case_of_one(setup_t *settings, flags_t *flags_available, int size)
{
    settings->fd = opendir(".");
    settings->file = readdir(settings->fd);
    for (; settings->file != NULL; settings->file = readdir(settings->fd))
        if (settings->file->d_name[0] != '.') {
            flag_L(settings, flags_available, size);
            my_putstr(settings->file->d_name);
            write(1, "\n", 1);
        }
    exit (EXIT_SUCCESS);
}