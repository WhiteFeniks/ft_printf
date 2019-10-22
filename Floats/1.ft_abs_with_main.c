#include <stdio.h>
#include <stdlib.h>

int ft_abs(int digital)                  // функция модуля
{
    if (digital < 0)
        digital = (-1) * digital;
    return (digital);
}

int main()
{
    int a = -5;
    a = ft_abs(a);
    printf("%d", a);
}