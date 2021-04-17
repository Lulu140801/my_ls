/*
** EPITECH PROJECT, 2020
** d_tiret
** File description:
** my_ls
*/

#include "../lib/my.h"

void correct(int ac, char **av)
{
    struct stat sb;
    int count = 0;

    for (int nb = 2, verif = 0; ac != 2; nb++, ac--) {
        verif = stat(av[nb], &sb);
        if (verif >= 0) {
            my_putstr(av[nb]);
            my_putstr("  ");
            count = 1;
        }
    }
    if (count == 1)
        my_putstr("\n");
}

void error(int ac, char **av)
{
    struct stat sb;

    for (int nb = 2, verif = 0; ac != 2; nb++, ac--) {
        verif = stat(av[nb], &sb);
        if (verif < 0) {
            my_putstr("ls: cannot access '");
            my_putstr(av[nb]);
            my_putstr("': No such file or directory");
            my_putstr("\n");
        }
    }
}

void d_tiret(int ac, char **av)
{
    if (ac == 2) {
        my_putstr(".");
        my_putstr("\n");
        return;
    }
    error(ac, av);
    correct(ac, av);
}
