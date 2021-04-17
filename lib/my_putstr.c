/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** Display the characters of a string
*/

#include <unistd.h>
#include "my.h"

void my_putstr(char const *str)
{
    int nb = 0;

    while (str[nb] != '\0') {
        write(1, &str[nb], 1);
        nb++;
    }
}

