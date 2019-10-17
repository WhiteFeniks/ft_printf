#include <stdio.h>
#include <stdlib.h>

int *ft_make_zero_str(int size)
{
    int *s;
    int i;

    i = 0;
    if (size == 0)
        return(0);
    if (!(s = (int *)malloc(sizeof(int) * size)))
        return (NULL);
    while(i < size)
    {
        s[i] = 0;
        i++;
    }
    return(s);
}

int    *ft_addition_long_arithmetic(int *x, int *y)
{
    int *result;
    int i;

    i = 1100 - 1;
    result = ft_make_zero_str(1100);
    while (i >= 0)
    {
        result[i] = result[i] + x[i] + y[i];
        if ((result[i] >= 10) && (i != 0))
        {
            result[i - 1] = result[i - 1] + 1;
            result[i] = result[i] % 10;
        }
        i--;
    }
    return(result);
}

int    *ft_exponentiation_long_arithmetic(int power)
{
    int *result;

    result = ft_make_zero_str(1100);
    result[1100 - 1] = 2;
    if (power == 0)
    {
        result[1099] = 1;
        return (result);
    }
    while (power-- > 1)
            result = ft_addition_long_arithmetic(result, result);
    return (result);
}