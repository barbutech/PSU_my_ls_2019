/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_str_allocate_and_cat.c
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/structures.h"
#include "../include/my.h"

char *my_str_allocate_and_cat(char *dest, char *src)
{
    int size_dest = my_strlen(dest);
    int size_src = my_strlen(src);
    int count = 0;

    if (size_dest == 0)
        return (src);
    if (size_src == 0)
        return (dest);
    char *tmp = malloc(sizeof(char) * (size_src + size_dest + 1));

    for (; dest[count] != '\0'; count++)
        tmp[count] = dest[count];
    for (int copy = 0; src[copy] != '\0'; copy++, count++)
        tmp[count] = src[copy];
    tmp[count] = '\0';
    return (tmp);
}