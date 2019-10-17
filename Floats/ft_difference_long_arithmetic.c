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

int    *ft_difference_long_arithmetic(int *x, int *y)
{
    int *result;
    int i;
    int count;

    i = 0;
    result = ft_make_zero_str(1100);
    while  (x[i] == 0)
        i++;
    count = 1100 - i;
    i = 1100;
    while (--i >= (1100 - count))
    {
        if (x[i] >= y[i])
            result[i] = x[i] - y[i];
        else
        {
            result[i] = 10 + x[i] - y[i];
            x[i - 1] = x[i - 1] - 1;
        }
    }
    return(result);
}