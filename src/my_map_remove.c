/*
** ETNA PROJECT, 02/04/2021 by la_t
** my_crd
** File description:
**      remove element from hashmap
*/

#include <stdlib.h>
#include "../include/my_map.h"

void list_destroy(struct hash_slot *list)
{
    if (list)
        list_destroy(list->next);
    free(list);
}

void hash_free(struct hash_set *set)
{
    for (size_t i = 0; i < set->size; i++) {
        list_destroy(set->slots[i]);
    }
    free(set->slots);
    free(set);
}

signed long long int hash_remove(struct hash_set *set, signed long long int key)
{
    size_t hash_index = set->hf(key, set->size);
    struct hash_slot *tmp = set->slots[hash_index];
    struct hash_slot *prev = tmp;

    if (tmp && tmp->key == key) {
        set->slots[hash_index] = set->slots[hash_index]->next;
        signed long long int value = tmp->value;
        free(tmp);
        return (value);
    }
    while (tmp && tmp->key != key) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (!tmp)
        return -1;
    signed long long int value = tmp->value;
    prev->next = tmp->next;
    free(tmp);
    return value;
}
