/*
** ETNA PROJECT, 02/04/2021 by la_t
** my_crd
** File description:
**      initiation of a map
*/

#include "../include/my_map.h"
#include <stdlib.h>

struct hash_set *hash_init(size_t size, hash_function hf)
{
    struct hash_set *my_hash = malloc(sizeof(struct hash_set));

    if (!my_hash)
        return NULL;
    my_hash->size = size;
    my_hash->hf = hf;
    my_hash->slots = calloc(sizeof(struct hash_slot *) * my_hash->size, 1);
    return my_hash;
}
