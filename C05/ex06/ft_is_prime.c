#include <stdio.h>

int	sqrt(int n)
{
	
}

int	ft_is_prime(int nb)
{
	int	i;

	if(nb == 1 || nb == 0)
		return (0);
	i = 2;
	while (nb < sqrt(n) + 1)
	{
		if (nb % i == 0)
			return 0;
		i++;
	}
	return (1);
}

int main()
{
	int n = 7;
	printf("%d", ft_is_prime(n));
	return (0);
}
