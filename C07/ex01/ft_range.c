#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	numbers;
	int	*arr;
	
	if ((max - min) <= 1)
		return (NULL);
	numbers = max - min;
	arr = malloc(numbers * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < numbers)
	{
		arr[i] = min + i;
		i++; 
	}
	return (arr);
}

int main(void)
{
	int a = 1;
	int b = 11;
	int *arr = ft_range(a, b);
	int range = b - a; 
	int i;

	i = 0;
	while (i < range)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	free(arr);
}
