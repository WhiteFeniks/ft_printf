#include <stdio.h>
#include <stdlib.h>

int *ft_make_zero_str(int size)
{
    int *s;                                                                 // создаем строку
    int i;

    i = 0;
    if (size == 0)                                                          // если размер нулевой
        return(0);                                                          // то 0
    if (!(s = (int *)malloc(sizeof(int) * size)))
        return (NULL);                                                      // если строка пустая, то NULL
    while(i < size)                                                         // идем по строке и зануляем ее
    {
        s[i] = 0;
        i++;
    }
    return(s);                                                              // возварщаем int-ую нулевую строку
}

int    *ft_difference_long_arithmetic(int *x, int *y)
{
    int *result;                                                            // результат вычитания
    int i;
    int count;

    i = 0;                                                                  // начинаем с элемента = длина результата - 1 (последний символ для \0)
    result = ft_make_zero_str(1100);                                   // создание нулевой int-овой строки
    while  (x[i] == 0)
        i++;
    count = 1100 - i;
    i = 1100;
    while (--i >= (1100 - count))                                           // начинаем с конца (вычитание столбиком)
    {
        if (x[i] >= y[i])                                                   // если разряд в первом числе больше
            result[i] = x[i] - y[i];                                        // разряда 2-го числа то просто вычитаем
        else
        {                                                                   // иначе занимаем 10 и вычитаем
            result[i] = 10 + x[i] - y[i];
            x[i - 1] = x[i - 1] - 1;                                        // при этом разряд слева уменьшаем на 1
        }
    }
    return(result);
}

int main()
{
    int *a;
    int *b;
    int *c;                                                                 // результат вычитания
    int acc;
    int i;

    i = 0;
    acc = 1100;
    a = ft_make_zero_str(1100);
    b = ft_make_zero_str(1100);
    a[1099] = 1;                                                            // 1 число из него вычитают
    a[1098] = 2;
    a[1097] = 3;
    a[1096] = 4;
    a[1095] = 5;


    b[1099] = 5;                                                            // 2 число (зеркально)
    b[1098] = 4;
    b[1097] = 3;
    b[1096] = 2;
    b[1095] = 1;

    c = ft_difference_long_arithmetic (a, b);                               // запуск функции вычитания длинной арифметики
    /* printf("%d", c[1092]); */
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