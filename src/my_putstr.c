/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_putstr.c
*/

#include <unistd.h>

int my_putstr(char *str)
{
    int count = 0;

    for (; str[count] != '\0'; count++);
    write (1, str, count);
}