/*
** EPITECH PROJECT, 2020
** My.h
** File description:
** Header on my lib
*/

#ifndef MY_H
#define MY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

void my_putstr(char const *str);
void d_tiret(int ac, char **av);
void l_tiret(int ac, char **av);
void R_tiret(int ac, char **av);
void r_tiret(int ac, char **av);
void t_tiret(int ac, char **av);

#endif
