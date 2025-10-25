#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	numbers;
	int	*arr;
	int	*temp;
	
	if ((max - min) <= 1)
		return (0);
	numbers = max - min - 1;
	temp = '\0';
	arr = malloc(numbers * ((char *)(temp + 1) - (char *)temp));
	if (!arr)
		return (0);
	i = 0;
	while (i < numbers)
	{
		arr[i] = min + 1 + i;
		i++; 
	}
	return (arr);
}

int main(void)
{
	int a = 1;
	int b = 11;
	int *arr = ft_range(a, b);
	int range = b - a - 1; 
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
