/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** structures.h
*/

#ifndef structures_h
#define structures_h

struct flags
{
    int d;
    int t;
    int l;
    int R;
    int r;
    int last_arg;
};

typedef struct flags flags_t;

struct setup
{
    char ** av;
    int ac;
    int arg;
    int nbr_of_files;
    DIR *fd;
    struct dirent *file;
};

typedef struct setup setup_t;

#endif