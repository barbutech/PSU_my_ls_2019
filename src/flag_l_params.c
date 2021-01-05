/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** flag_l_params.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

void type_arg(struct stat file_stat)
{

    S_ISDIR(file_stat.st_mode) ? write(1, "d", 1) : 0;
    S_ISREG(file_stat.st_mode) ? write(1, "-", 1) : 0;
    S_ISCHR(file_stat.st_mode) ? write(1, "c", 1) : 0;
    S_ISBLK(file_stat.st_mode) ? write(1, "b", 1) : 0;
    S_ISLNK(file_stat.st_mode) ? write(1, "l", 1) : 0;
    S_ISFIFO(file_stat.st_mode) ? write(1, "c", 1) : 0;
    S_ISSOCK(file_stat.st_mode) ? write(1, "s", 1) : 0;
}

void rights_arg(struct stat file_stat)
{
    file_stat.st_mode & S_IRUSR ? write (1, "r", 1) : write(1, "-", 1);
    file_stat.st_mode & S_IWUSR ? write (1, "w", 1) : write(1, "-", 1);
    file_stat.st_mode & S_IXUSR ? write (1, "x", 1) : write(1, "-", 1);
    file_stat.st_mode & S_IRGRP ? write (1, "r", 1) : write(1, "-", 1);
    file_stat.st_mode & S_IWGRP ? write (1, "w", 1) : write(1, "-", 1);
    file_stat.st_mode & S_IXGRP ? write (1, "x", 1) : write(1, "-", 1);
    file_stat.st_mode & S_IROTH ? write (1, "r", 1) : write(1, "-", 1);
    file_stat.st_mode & S_IWOTH ? write (1, "w", 1) : write(1, "-", 1);
    file_stat.st_mode & S_IXOTH ? write (1, "x", 1) : write(1, "-", 1);
    write(1, " ", 1);
}

void print_name_and_group(struct stat file_name)
{
    struct passwd *pwd = getpwuid(file_name.st_uid);
    struct group * group = getgrgid(pwd->pw_gid);

    write(1, " ", 1);
    my_putstr(pwd->pw_name);
    write(1, " ", 1);
    my_putstr(group->gr_name);
    write(1, " ", 1);
    my_put_nbr(file_name.st_size);
    write(1, " ", 1);
}

void find_month(char *complete)
{
    int count = 0;
    char *month = malloc(sizeof(char) * 4);
    month[3] = '\0';

    for (; complete[count] != ' '; count++);
    count++;
    for (int copy = 0; complete[count] != ' '; count++, copy++)
        month[copy] = complete[count];
    my_putstr(month);
    write(1, " ", 1);
}

void time_param(struct stat file_stat)
{
    char *complete = ctime(&file_stat.st_mtime);
    int count = 0;

    find_month(complete);
    for (; complete[count] < '0' || complete[count] > '9'; count++);
    for (; complete[count] >= '0' && complete[count] <= '9'; count++)
        my_putchar(complete[count]);
    write(1, " ", 1);
    count++;
    for (int size = 5; size > 0; size--, count++)
        my_putchar(complete[count]);
    write(1, " ", 1);
}