/*
** ETNA PROJECT, 02/04/2021 by la_t
** my_crd
** File description:
**      push new elements in the hashmap
*/

#include "../include/my_map.h"
#include <stdlib.h>

int hash_insert(struct hash_set *set, signed long long int key, signed long long int value)
{
    int hash_index = set->hf(key, set->size);
    struct hash_slot *tmp = set->slots[hash_index];
    
    while (tmp && tmp->key != key)
        tmp = tmp->next;
    if (!tmp) {
        struct hash_slot *new = malloc(sizeof(struct hash_slot));
        if (!new)
            return 0;
        new->value = value;
        new->key = key;
        new->next = set->slots[hash_index];
        set->slots[hash_index] = new;
        return 1;
    }
    tmp->value = value;
    return 1;
}
