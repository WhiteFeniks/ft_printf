#include <stdio.h>
#include <stdlib.h>

int *ft_shift_elements(int *my_array, int len)
{
    int i;

    i = 0;
    while(my_array[i] == 0)
        i++;
    while (i < 1100)
    {
        my_array[i - len] = my_array[i];
        my_array[i] = 0;
        i++;
    }
    return(my_array);
}