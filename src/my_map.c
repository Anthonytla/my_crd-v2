/*
** ETNA PROJECT, 02/04/2021 by la_t
** my_crd
** File description:
**      my_map_lookup
*/

#include <stdlib.h>
#include "../include/my_map.h"

size_t basic_hash_function(signed long long int key, size_t table_size)
{
    return key % table_size;
}

signed long long int hash_find(const struct hash_set *set, signed long long int key)
{
    size_t hash_index = set->hf(key, set->size);
    struct hash_slot *tmp = set->slots[hash_index];
    while (tmp && (tmp->key != key))
        tmp = tmp->next;
    if (!tmp)
        return -1;
    return tmp->value;
}
