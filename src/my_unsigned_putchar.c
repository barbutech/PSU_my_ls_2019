/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_unsigend_putchar.c
*/

#include <unistd.h>

void my_unsigned_putchar(unsigned char c)
{
    write(1, &c, 1);
}