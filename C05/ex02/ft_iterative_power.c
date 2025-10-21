#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	product;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	product = 1;
	while (power > 0)
	{
		product *= nb;
		power--;
	}
	return (product);
}

int main()
{
	int n = 9;
	int p = 2;

	printf("%d", ft_iterative_power(n, p));
	return (0);
}
