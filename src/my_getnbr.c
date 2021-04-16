/*
** ETNA PROJECT, 16/03/2021 by la_t
** my_getnbre
** File description:
**      convert str to number
*/

int get_sign(const char *str)
{
    int sign = 1;

    while (str[0] == '-' || str[0] == '+') {
        if (str[0] == '-')
            sign = sign * -1;
        else if (str[0] != '+' && str[0] != '-')
            break;
        str++;
    }
    return sign;
}

int getnblength(const char **str)
{
    int i = 0;
    
    while ((*str)[0] <= '0' || (*str)[0] > '9') {
        if (((*str)[0] >= 'A' && (*str)[0] <= 'Z')
            || ((*str)[0] >= 'a' && (*str)[0] <= 'z'))
            break;
        *str = *str + 1;
    }
    
    while ((*str)[i] <= '9' && (*str)[i] >= '0')
        i++;
    return i;
}

signed long long int my_pow(int a, int b)
{
    signed long long int c = 1;

    for (int i = 0; i < b; i++)
        c = c * a;
    return c;
}

signed long long int my_getnbr(const char *str)
{
    int sign;
    int len;
    signed long long int res = 0;
    signed long long int tmp;
    
    if (str[0] == ' ' || str[0] == '0')
        return 0;
    sign = get_sign(str);
    len = getnblength(&str);
    for (int i = 0; i < len; i++) {
        tmp = str[i] - '0';
        res += tmp * my_pow(10, len - 1 - i);
    }
    return sign > 0 ? res : -res;
}
        
    
