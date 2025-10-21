#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	fact_val;

	if (nb < 0)
		return (0);

	fact_val = 1;
	while (nb > 1)
	{
		fact_val = fact_val * nb;
		nb--;
	}
	return (fact_val);
}

int main()
{
	int m = 5;
	
	printf("%d", ft_iterative_factorial(m));
	return (0);
}
