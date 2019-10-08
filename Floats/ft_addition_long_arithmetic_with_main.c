#include <stdio.h>
#include <stdlib.h>

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

int    *ft_addition_long_arithmetic(int *x, int *y, int accuracy)
{
    int *result;                                                            // результат сложения
    int i;

    i = accuracy - 1;                                                       // начинаем с элемента = длина результата - 1 (последний символ для \0)
    result = ft_make_zero_str(accuracy);                                    // создание нулевой int-овой строки
    while (i >= 0)                                                          // начинаем с конца (сложение столбиком)
    {
        result[i] = result[i] + x[i] + y[i];                                // складываем поочередно элементы элементы
        if ((result[i] >= 10) && (i != 0))                                  // если получилось число больше 10 и i не нулевой элемент
        {
            result[i - 1] = result[i - 1] + 1;                              // то в следующий символ левее текущего прибавим 1
            result[i] = result[i] % 10;                                     // а в ячейке с i-ым элементом перепишем остаток от деления на 10
        }
        i--;
    }
    return(result);                                                         // выводим результат сложения
}

int main()
{
    int a[] = {0, 8, 9, 3};                                                 // 1 число
    int b[] = {0, 6, 4, 8};                                                 // 2 число
    int *c;                                                                 // результат сложения
    int acc = 4;                                                            // точность(количество элементов результата)
    int i = 0;

    c = ft_addition_long_arithmetic (a, b, acc);                            // запуск функции сложения длинной арифметики
    while(i < acc)                                                          // вывод по-символьно полученного результата
    {
        printf("%d", c[i]);
        i++;
    }
    return 0;
}