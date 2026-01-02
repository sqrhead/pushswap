#include "push_swap.h"

int ft_strlen(const char *str)
{
    int count;

    count = 0;
    while (*str)
    {
        count ++;
        str ++;
    }
    return (count);
}

long    ft_atol(char *str)
{
    long result;
    int index;
    int sign;

    result = 0;
    index = 0;
    sign = 1;
    while (str[i])
    {
        if (str[i] == '-')
        {
            sign = sign * -1;
            i ++;
        }
        else if (str[i] == '+')
            i ++
    }
    while (str[i])
    {
        result = result * 10 + (str[i] - '0');
        i ++;
    }

    return (result * sign);
}
