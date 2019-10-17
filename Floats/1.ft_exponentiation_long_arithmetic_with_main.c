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

int    *ft_addition_long_arithmetic(int *x, int *y)                         //функция сложения столбиком смотри комментарии отдельно
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

int    *ft_exponentiation_long_arithmetic(int power)                    // функция возведения в степень двойки (основание 2)
{
    int *result;                                                        // результат возведения в степень

    result = ft_make_zero_str(1100);                               // обнулем массив из 1100 элементов
    result[1100 - 1] = 2;                                              // записываем в 1099 элемент 2-ку (последний элемент)
    if (power == 0)                                                    // обработка исключения: если степень равна 0
    {
        result[1099] = 1;
        return (result);
    }
    while (power-- > 1)                                                // пока степень больше 1 уменьшаем
            result = ft_addition_long_arithmetic(result, result);      // складываем power - 1 раз (pow = 3 -> 2 + 2 = 4, 4 + 4 = 8-> ответ 8)
    return (result);
}

int main()
{
    int *c;                                                           // результат возведения в степень
    int pow;                                                          // степень в которую необходимо возвести
    int i;

    i = 0;
    pow = 37;
    c = ft_exponentiation_long_arithmetic(pow);
    while(c[i] == 0 && i < 1100)                                      // вывод по символьно результата
        i++;
    if (i == 1100)
        printf("%d", 0);
    while(i < 1100)
    {
        printf("%d", c[i]);
        i++;
    }
    return 0;
}

