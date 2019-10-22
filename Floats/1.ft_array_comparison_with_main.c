#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_array_comparison(int *my_array)                                      // подсчет значащих элемнтов в массиве
{
    int i;
    int count;                                                              // количество значащих элемнтов

    count = 0;
    i = 0;
    while(my_array[i] == 0)                                                 // идем по массиву по не наткнемся на значащий элементов
        i++;
    while (i < 1100)                                                        // считаем количество элементов
    {
        i++;
        count++;
    }
    return (count);                                                         // возвращаем подсчитанное количество элементов
}

int *ft_make_zero_str(int size)
{
    int *s;                                                                 // создаем строку
    int i;

    i = 0;
    if (size == 0)                                                          // если размер нулевой
        return(0);                                                          // то 0
    if (!(s = (int *)malloc(sizeof(int) * (size + 1))))
        return (NULL);                                                      // если строка пустая, то NULL
    while(i < size)                                                         // идем по строке и зануляем ее
    {
        s[i] = 0;
        i++;
    }
    s[i] = '\0';                                                            // последний элемент для \0
    return(s);                                                              // возварщаем int-ую нулевую строку
}

int main()
{
    int *a;
    int c;

    a = ft_make_zero_str(1100);
    a[1099] = 0;                                                            // число
    a[1098] = 0;
    a[1097] = 0;
    a[1096] = 0;
    a[1095] = 4;
    c = ft_array_comparison(a);                                             //подсчет количества значащих элементов
    printf("количество значащих элементов в массиве а = %d \n", c);
    return 0;
}