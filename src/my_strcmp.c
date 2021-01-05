/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_strcmp.c
*/

int my_strcmp(char *dest, char *src)
{
    int size_dest = 0;
    int size_src = 0;
    int ret = 0;

    for (int count = 0; dest[count] != '\0'; count++)
        size_dest = size_dest + dest[count];
    for (int count = 0; src[count] != '\0'; count++)
        size_src = size_src + src[count];
    ret = size_dest - size_src;
    return (ret);
}