/*
** ETNA PROJECT, 02/04/2021 by la_t
** my_crd
** File description:
**      main.c
*/

#include "../include/my_map.h"
#include <stdlib.h>

static void my_putstr(const char *str)
{
    while (str[0]) {
        my_putchar(str[0]);
        str++;
    }
}

static void my_free(char **argv)
{
    int i = 0;
    while (argv[i]) {
        free(argv[i]);
        i++;
    }
    free(argv);
}

static void data_management(char **argv, struct hash_set *my_hash) 
{
    if (argv[0]) {
        signed long long int key = my_getnbr(argv[0]);
        if (argv[0][0] > '9' || argv[0][0] < '0') {
            my_putstr("-1\n");
        }
        else if (!argv[1]) {
            my_putnbr(hash_find(my_hash, key));
            my_putchar('\n');
        }
        else if (argv[1][0] == 'D') {
            my_putnbr(hash_remove(my_hash, key));
            my_putchar('\n');
        }
        else if (argv[1][0] != 'D' && argv[1][0] >= '0' && argv[1][0] <= '9') {
            hash_insert(my_hash, key, my_getnbr(argv[1]));
            my_putnbr(key);
            my_putchar('\n');
        } else
            my_putstr("-1\n");
    }
}
int main(void) 
{
    char *str = NULL;
    struct hash_set *my_hash = hash_init(100, basic_hash_function);
    
    while ((str = my_readline())) {
        char **argv = my_str_to_word_array(str);
        data_management(argv, my_hash);
        free(str);
        my_free(argv);
    }
    hash_free(my_hash);
}
