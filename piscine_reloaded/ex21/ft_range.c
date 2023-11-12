#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	i;

	if (min >= max)
		return (0);
	result = (int*)malloc(sizeof(int) * (max - min));
	i = 0;
	while (max > min)
	{
		result[i] = min;
		min++;
		i++;
	}
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	int	min;
	int	max;
	int	*tab;
	int	i;

	i = 0;
	min = 5;
	max = 10;
	tab = ft_range(min, max);
	while(i < (max - min))
	{
		printf("%d, ", tab[i]);
		i++;
	}
}*/
