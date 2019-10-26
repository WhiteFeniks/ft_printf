#include <stdio.h>
#include <stdlib.h>

int *ft_make_zero_str(int size)
{
    int *s;
    int i;

    i = 0;
    if (size == 0)
        return(0);
    if (!(s = (int *)malloc(sizeof(int) * (size + 1))))
        return (NULL);
    while(i < size)
    {
        s[i] = 0;
        i++;
    }
    s[i] = '\0';
    return(s);
}

int ft_shift_one(int len)
{
    int result;

    if (len == 0)
        return (1);
    result = 10;
    while (--len > 0)
        result = result * 10;
    return (result);
}

int ft_make_number(int *my_array)
{
    int i;
    int num;

    i = 0;
    num = 0;
    while (my_array[i] == 0)
        i++;
    while (i < 1100)
    {
        num = num + my_array[i] * ft_shift_one(1100 - i - 1);
        i++;
    }
    return (num);
}

int	ft_array_length(int *my_array)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(my_array[i] == 0)
        i++;
    while (i < 1100)
    {
        i++;
        count++;
    }
    return (count);
}

int *ft_shift_elements_left(int *my_array, int len)
{
    int i;

    i = 0;
    while(my_array[i] == 0)
        i++;
    while (i < 1100)
    {
        my_array[i - len] = my_array[i];
        if (len != 0)
            my_array[i] = 0;
        i++;
    }
    return(my_array);
}

int *ft_shift_elements_right(int *my_array, int len)
{
    int i;

    i = 1100;
    while (my_array[i] == 0)
        i--;
    while (i >= 0)
    {
        my_array[i + len] = my_array[i];
        if (len != 0)
            my_array[i] = 0;
        i--;
    }
    return(my_array);
}

int ft_align_digital(int digital)
{
    digital = digital * 10;
    return (digital);
}

int    *ft_division_long_arithmetic(int *x, int *y)
{
    int number_1;
    int number_2;
    int *result;
    int i;
    int len;

    number_1 = 0;
    number_2 = 0;
    i = 0;
    result = ft_make_zero_str(1100);
    len = (ft_array_length(y) - ft_array_length(x));
    x = ft_shift_elements_left(x, len);
    number_1 = ft_make_number(x);
    number_2 = ft_make_number(y);
    while (number_1 % number_2 != 0)
    {
        while (number_1 / number_2 <= 0)
            number_1 = ft_align_digital(number_1);
        result[i] = number_1 / number_2;
        number_1 = number_1 % number_2;
        i++;
    }
    ft_shift_elements_right(result, len);
    return (result);
}