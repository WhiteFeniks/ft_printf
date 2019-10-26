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

int ft_shift_one(int len)            // в этой функции приходит количество нулей, если 2 нуля, то возвращается 100; если 3 -> 1000
{
    int result;

    if (len == 0)                    // если длина 0, то возвращаем 1
        return (1);
    result = 10;
    while (--len > 0)               // пока len > 0 уменьшаем его
        result = result * 10;
    return (result);                // возвращается в зависисмости от количества нулей len, если 2 нуля -> то 100, если 3 -> 1000
}

int ft_make_number(int *my_array)                                  // функция создания из массива числа int
{
    int i;
    int num;

    i = 0;
    num = 0;
    while (my_array[i] == 0)                                       // идем по массиву пока не наткнемся на значащие элементы
        i++;
    while (i < 1100)                                               // идем до 1100
    {
        num = num + my_array[i] * ft_shift_one(1100 - i - 1);  // получаем например из массива [4,2,1] -> 400 + 20 + 1 = 421
        i++;
    }
    return (num);
}

int	ft_array_length(int *my_array)      // подсчитывает число значащих элементов массива
{
    int i;
    int count;                          // число значащих элементов массива

    i = 0;
    count = 0;
    while(my_array[i] == 0)             // идем до тех пор пока не наткнемся на значащий элемент (!= 0)
        i++;
    while (i < 1100)                    // идем и считаем до 1100 количество значащих элементов
    {
        i++;
        count++;
    }
    return (count);                     // вывод числа значащих элементов массива
}

int *ft_shift_elements_left(int *my_array, int len)      // сдвигаем каждый элемент влево на определенную длину len
{
    int i;

    i = 0;
    while(my_array[i] == 0)                             // идем до тех пор пока не наткнемся на значащий элемент (!= 0)
        i++;
    while (i < 1100)                                    // идем до 1100
    {
        my_array[i - len] = my_array[i];                // в элемент с номером i - len перезаписываем наш i-ый элемент
        if (len != 0)                                   // чтобы не перезаписывало нулем наши элементы когда len = 0
            my_array[i] = 0;                            // обнуляем наши перенесенные i-ые элементы
        i++;
    }
    return(my_array);                                   // возвращаем массив свдинутый влево на длину len
}

int *ft_shift_elements_right(int *my_array, int len)    // аналогично свдигу влево, только двигаем теперь вправо
{
    int i;

    i = 1100;                                           // идем с 1100
    while (my_array[i] == 0)                            // пока не наткнемся на значащий элемент
        i--;
    while (i >= 0)                                      // идем до 0
    {
        my_array[i + len] = my_array[i];                // перезаписываем в i + len элемент наш i-ый элемент
        if (len != 0)                                   // чтобы не перезаписывало нулем наши элементы когда len = 0
            my_array[i] = 0;                            // обнуляем наши перенесенные i-ые элементы
        i--;
    }
    return(my_array);                                   // возвращаем массив свдинутый вправо на длину len
}

int ft_align_digital(int digital)           // дописывает в числе справа 0 (умножает на 10 )
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
    result = ft_make_zero_str(1100);                   // создаем нулевой массив result
    len = (ft_array_length(y) - ft_array_length(x));        // смотрим на сколько разрядов отличаются число 1 от числа 2
    x = ft_shift_elements_left(x, len);                     // смещаем влево наше число 1, чтобы они выровнялись по длине
    number_1 = ft_make_number(x);                           // переписываю из массива x в число number 1 [4,2,1] -> 421
    number_2 = ft_make_number(y);                           // переписываю из массива y в число number 1 [1,8,9] -> 189
    while (number_1 % number_2 != 0)                        // пока остаток от деления первого числа на второе не равно 0 делаем цикл
    {
        while (number_1 / number_2 <= 0)                    // если первое число не делится на второе например 1 / 128 (целочисленное деление 1-го на 2-ое )
            number_1 = ft_align_digital(number_1);          // увеличиваем на 0 справа от числа в цикле 10->100->1000, дальше уже 1000 / 128 > 0 выходим из цикла
        result[i] = number_1 / number_2;                    // в result[0] записываем первый результат деления, в result[1] записываем второй результат деления и т.д.
        number_1 = number_1 % number_2;                     // переписываем вместо первого числа остаток от деления
        i++;
    }
    ft_shift_elements_right(result, len);                   // смещаем вправо числа на количество разрядов 
    return (result);
}

int main()
{
    int *a;
    int *b;
    int *c;                                                                 // результат вычитания

    int i;

    i = 0;
    a = ft_make_zero_str(1100);
    b = ft_make_zero_str(1100);
    a[1099] = 1;                                                            // 1 число из него вычитают
    a[1098] = 0;
    a[1097] = 0;
    a[1096] = 0;
    a[1095] = 0;


    b[1099] = 6;                                                            // 2 число (зеркально)
    b[1098] = 9;
    b[1097] = 0;
    b[1096] = 4;
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

/*
int ft_abs(int digital)
{
    if (digital < 0)
        digital = (-1) * digital;
    return (digital);
}

int ft_len_int(int digital)
{
    int count;

    count = 0;
    while(digital > 0)
    {
        digital = digital / 10;
        count++;
    }
    return (count);
}
*/