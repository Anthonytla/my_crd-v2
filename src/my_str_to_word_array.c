/*
** ETNA PROJECT, 17/03/2021 by moulin_e
** my_str_to_word_array
** File description:
**      transform string to array
*/

#include <stdlib.h>

int is_alpha(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'));
}

int get_nb_word(const char *str)
{
    int count = 1;
    
    while (str[0] == ' ')
        str++;
    if (!str[0] || str[0] == ' ')
        return 0;
    
    while (!is_alpha(str[0]))
        str++;
    while (str[0]) {
        while (!is_alpha(str[0]) && is_alpha(str[1])) {
            str++;
            count++;
        }
        str++;
    }
    return count;
}

int get_word_length(const char *str)
{
    int len = 0;

    while (!is_alpha(str[0]))
        str++;
    while (str[0]) {
        if (is_alpha(str[0])) {
            len++;
            str++;
        } else
            break;
    }
    return len;
}

char **my_str_to_word_array(const char *str)
{
    int nb_words = get_nb_word(str);
    char **argv = malloc(sizeof(char *) * (nb_words + 1) + 1);
    int w_len;
    
    for (int i = 0; i < nb_words; i++) {
        w_len = get_word_length(str);
        argv[i] = malloc(sizeof(char) * w_len + 1);

        while (!is_alpha(str[0]))
               str++;
        for (int j = 0; j < w_len; j++) {
            argv[i][j] = str[0];
            str++;
        }
        argv[i][w_len] = '\0';
    }
    argv[nb_words] = NULL;
    return argv;
}
