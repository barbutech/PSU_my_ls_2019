/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my.h
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include "../include/structures.h"

flags_t *parse(int , char **, flags_t *);
int flag_d(setup_t *);
void flag_L(setup_t *, flags_t *, int);
struct dirent *erno_and_fd(setup_t *);
void error_and_dirmanagement(setup_t **, int);
void case_of_folder(setup_t *, flags_t *, int);
void case_of_one(setup_t *, flags_t *, int);
void my_unsigned_putchar(unsigned char);
void type_arg(struct stat);
void rights_arg(struct stat);
void print_name_and_group(struct stat);
void time_param(struct stat);
int my_put_nbr(int);
void my_putchar(char);
int my_strcmp(char *, char *);
int my_putstr(char *);
int my_strlen(char *);
char *my_str_allocate_and_cat(char *, char *);