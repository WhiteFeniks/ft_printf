#include <stdio.h>
#include <stdlib.h>

int	ft_array_comparison(int *my_array)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while(my_array[i] == 0)
        i++;
    while (i < 1100)
    {
        i++;
        count++;
    }
    return (count);
}

