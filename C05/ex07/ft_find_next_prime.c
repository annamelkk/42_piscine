#include <stdio.h>

int	ft_sqrt(int n)
{
	int	i;
	if (n <= 0)
		return (0);
	i = 1;
	while (i * i <= n)
	{
		if (i * i == n)
			return (i);
		i++;
	}
	return (0);
}

int	ft_is_prime(int nb)
{
	int	i;

	if(nb == 1 || nb == 0)
		return (0);
	if (nb == 2)
		return (1);
	i = 2;
	while (i < ft_sqrt(nb) + 1)
	{
		if (nb % i == 0)
			return 0;
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}


int main()
{
	int n = 4;
	printf("%d", ft_find_next_prime(n));
	return (0);
}
