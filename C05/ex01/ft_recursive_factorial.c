#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb <= 1)
		return (1);
	else 
		return nb * ft_recursive_factorial(nb - 1);	
}

int main()
{
	int n = 5;
	printf("%d", ft_recursive_factorial(n));
	return (0);
}
