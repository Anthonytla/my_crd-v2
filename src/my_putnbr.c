/*
** ETNA PROJECT, 02/04/2021 by la_t
** my_crd
** File description:
**      display number on stdout
*/

void my_putchar(char c);

int get_nbr_digits(signed long long int n)
{
    if (n < 0)
        n = -1 * (n / 10);
    else
        n = n / 10;
    int digit_count = 0;

    while (n > 0) {
        n = n / 10;
        digit_count++;
    }
    return digit_count + 1;
}

void my_putnbr(signed long long int n)
{
    if (n == 0) {
        my_putchar('0');
        return;
    }
    int nbr_digits = get_nbr_digits(n);
    signed long long int p = n > 0 ? n / 10 : -1 * (n / 10);

    if (n < 0)
        my_putchar('-');
    while (nbr_digits - 1 > 0) {
        signed long long int digit = p;

        for (int i = 0; i < nbr_digits - 2; i++)
            digit = (digit / 10);
        my_putchar(digit % 10 + '0');
        nbr_digits--;
    }
    signed long long int res = n > 0 ? (n % 10) : -1 * (n % 10);
    my_putchar(res + '0');
}
