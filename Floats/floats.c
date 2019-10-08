#include "floats.h"

int    *ft_intstr(int size)
{
    int    *str;
    int i;

    i = -1;
    if (!size)
        return (0);
    str = malloc(sizeof(int) * size);
    if (!str)
        return (NULL);
    while (++i < size)
        str[i] = 0;
    return (str);
}

int	*ft_long_math_summ(int *a, int *b, int acc)
{
    int *rez;
    int i;
    int j;

    i = acc - 1;
    j = acc - 1;
    rez = ft_intstr(acc);
    while (i != -1)
    {
        rez[i] += a[j] + b[j];
        while (rez[i] >= 10)
        {
            rez[i - 1] = rez[i] / 10;
            rez[i] = rez[i] % 10;
        }
        i--;
        j--;
    }
    return (rez);
}

int main()
{
    int a[] = {7, 2, 6};
    int b[] = {3, 4, 1};
    int *c;
    int acc = 3;
    int i = 0;

    c = ft_long_math_summ(a, b, acc);
    while(i < acc)
    {
        printf("%d", c[i]);
        i++;
    }
    return 0;
}