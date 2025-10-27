#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	
	if (max <= min)
	{
		*range = NULL;	
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min));
	if (!*range)
		return (-1);
	i = 0;
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}

int main(void)
{
	int a = 1;
	int b = 11;
	int i;
	int *arr;

	i = 0;
	while (i < ft_ultimate_range(&arr, a, b))
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	free(arr);
}
