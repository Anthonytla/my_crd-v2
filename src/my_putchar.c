/*
** ETNA PROJECT, 02/04/2021 by la_t
** my_crd
** File description:
**      display character function
*/

#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}
