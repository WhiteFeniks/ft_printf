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

int main()
{
    int *rez;
    rez = ft_make_zero_str(8);
    printf("%d", *rez);
}