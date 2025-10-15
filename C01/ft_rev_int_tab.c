#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int temp;

	i = 0;

	while ( i < size / 2 )
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - i - 1] = temp;
		i++;
	}
}


int main()
{
	int a[] = {1, 10, 50, 40};
	int size = 4;	

	ft_rev_int_tab(a, size);
	
	for(int i = 0; i < size; i++)
	{
		printf(" %d ", a[i]);
	} 
	
	return (0);
}
