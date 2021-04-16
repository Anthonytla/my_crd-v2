/*
** ETNA PROJECT, 30/03/2021 by la_t
** my_crd
** File description:
**      my_map.h
*/

#ifndef MY_MAP_H
#define MY_MAP_H

#include <stddef.h>

typedef size_t (*hash_function)(signed long long int key, size_t table_size);

struct hash_slot
{
    signed long long int key;
    signed long long int value;
    struct hash_slot *next;
};

struct hash_set
{
    struct hash_slot **slots;
    size_t size;
    hash_function hf;
};

size_t basic_hash_function(signed long long int key, size_t table_size);

struct hash_set *hash_init(size_t size, hash_function hf);

void list_destroy(struct hash_slot *list);

void hash_free(struct hash_set *set);

int hash_insert(struct hash_set *set, signed long long int key, signed long long int value);

signed long long int hash_remove(struct hash_set *set, signed long long int key);

signed long long int hash_find(const struct hash_set *set, signed long long int key);

void hash_dump(const struct hash_set *set);

void my_putchar(char c);

int get_sign(const char *str); 

int getnblength(const char **str);

signed long long int my_pow(int a, int b);   

signed long long int my_getnbr(const char *str);

int get_nbr_digits(signed long long int n);

void my_putnbr(signed long long int n);

char *my_readline(void);

int is_alpha(char c);

int get_nb_word(const char *str);

int get_word_length(const char *str);

char **my_str_to_word_array(const char *str);
#endif
