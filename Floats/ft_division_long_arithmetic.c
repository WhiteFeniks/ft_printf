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

int	ft_array_comparison(int *my_array)
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

int ft_abs(int digital)
{
    if (digital < 0)
        digital = (-1) * digital;
    return (digital);
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

int    *ft_division_long_arithmetic(int *x, int *y)
{
    int *result;                                                            // результат сложения
    int *temp_1;
    int *temp_2;
    int *temp_3;
    int i;
    int j;
    int count;
    int len;
    int len_x;
    int len_y;

    i = 0;                                                                  // начинаем с элемента = длина результата - 1 (последний символ для \0)
    j = 0;
    result = ft_make_zero_str(1100);                                   // создание нулевой int-овой строки
    len_x = ft_array_comparison(x);
    len_y = ft_array_comparison(y);
    len = ft_abs(len_x - len_y);
    if (len_x < len_y)                                                     //Здесь выбрается наименьшее число и выровнивается с большим
    {
        temp_1 = ft_shift_elements(x, len);
        temp_2 = y;
    }
    else
    {
        temp_1 = x;
        temp_2 = ft_shift_elements(y,len);
    }
    while (temp_1[i] == 0)
        i++;
    count = i;
    while (i < 1100)
    {
        result[0] = result[0] + temp_1[i] * ft_shift_one(1100 - i - 1);
        result[1] = result[1] + temp_2[i] * ft_shift_one(1100 - i - 1);
        i++;
    }
    while (--i >= count)
    {
        result[i] = result[0] / result[1];
        result[i - 1] = result[0] % result[1];
    }

    printf("good");
    return(result);                                                         // выводим результат сложения
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
    a[1099] = 4;                                                            // 1 число из него вычитают
    a[1098] = 0;
    a[1097] = 0;
    a[1096] = 0;
    a[1095] = 0;


    b[1099] = 1;                                                            // 2 число (зеркально)
    b[1098] = 2;
    b[1097] = 1;
    b[1096] = 0;
    b[1095] = 0;

    c = ft_division_long_arithmetic (a, b);                               // запуск функции вычитания длинной арифметики

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