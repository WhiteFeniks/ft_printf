include <stdlib.h>

int	*ft_make_zero_str(int size)
{
	int *s;
	int i;

	i = 0;
	if (size == 0)
		return (0);
	if (!(s = (int *)malloc(sizeof(int) * (size + 1))))
		return (NULL);
	while(i < size)
	{
		s[i] = 0;
		i++;
	}
	s[i] = '\0';
	return (s);
}
