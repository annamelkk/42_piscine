#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int temp;
	int sorted;

	sorted = 0;	

	while(!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < size - 1)
		{
			if ( tab[i + 1] < tab[i] )
			{
				temp = tab[i];
				tab[i] = tab[i+1];
				tab[i+1] = temp;
				sorted = 0;
			}
		i++;
		}
	}	
}

int main()
{
	int a[] = {1, 25, 10, 2, 0};
	int size = 5;

	ft_sort_int_tab(a, size);

	for(int i = 0; i < size; i++)
	{
		printf(" %d ", a[i]);
	}
	
	return (0);
}
