/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** do ls
*/

#include "../lib/my.h"

void secondaire(char **av, int nb)
{
    struct dirent *my_ls;
    DIR *dir;

    if ((dir = opendir(av[nb])) == NULL) {
        my_putstr("ls: cannot access '");
        my_putstr(av[nb]);
        my_putstr("': No such file or directory");
        return;
    }
    for (; (my_ls = readdir(dir));) {
        if(my_ls -> d_name[0] != '.') {
            my_putstr(my_ls->d_name);
            my_putstr("  ");
        }
    }
}

void principale()
{
    struct dirent *my_ls;
    DIR *dir;

    dir = opendir(".");
    for (; (my_ls = readdir(dir));) {
        if(my_ls -> d_name[0] != '.') {
            my_putstr(my_ls->d_name);
            my_putstr("  ");
        }
    }
}

int my_ls(int ac, char **av)
{
    if (ac == 1) {
        principale();
    } else if (ac == 2){
        secondaire(av, 1);
    } else {
        for (int nb = 1; ac != 1; nb++, ac--) {
            my_putstr(av[nb]);
            my_putstr(":\n");
            secondaire(av, nb);
            if (ac > 2)
                my_putstr("\n\n");
        }
    }
    return (0);
}

int compare(int ac, char **av)
{
    char operator[6] = "lRdrt";
    void (*send[6])() = {l_tiret, R_tiret, d_tiret, r_tiret, t_tiret};

    if (ac == 1) {
        my_ls(ac, av);
        my_putstr("\n");
        return (0);
    }
    for (int nb = 0; operator[nb] != '\0'; nb++) {
        if (operator[nb] == av[1][1] && av[1][0] == '-') {
            send[nb](ac, av);
            return (0);
        }
    }
    my_ls(ac, av);
    my_putstr("\n");
    return (0);
}

int main(int ac, char **av)
{
    if ((compare(ac, av)) == 84)
        return (84);
    return (0);
}
