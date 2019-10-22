#include <stdio.h>
#include <stdlib.h>

int *ft_shift_elements(int *my_array, int len)                             // сдвигает число влево на указанное количество
{
    int i;

    i = 0;
    while(my_array[i] == 0)                                                 // пока пусто идем дальше
        i++;
    while (i < 1100)                                                        // если наткунились на значащий элемент переписываем его
    {                                                                       // на заданное количество влево
        my_array[i - len] = my_array[i];
        my_array[i] = 0;
        i++;
    }
    return(my_array);                                                       // возвращаем массив, например если было 4 число свдигаем его на 2
}                                                                           // влево получаем 400

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
    int *c;
    int i;

    i = 0;
    a = ft_make_zero_str(1100);
    a[1099] = 4;                                                            // число
    a[1098] = 0;
    a[1097] = 0;
    a[1096] = 0;
    a[1095] = 0;
    c = ft_shift_elements(a, 2);                                             //подсчет количества значащих элементов
    while(c[i] == 0 && i < 1100)
        i++;
    if (i == 1100)
        printf("%d", 0);
    while(i < 1100)                                                         // вывод по-символьно полученного результата
    {
        printf("%d", c[i]);
        i++;
    }
    return 0;
}