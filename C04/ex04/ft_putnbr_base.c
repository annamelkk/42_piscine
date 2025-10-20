#include <unistd.h>


int	validate_length(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
	i++;
	}
	if (i < 2)
		return (0);
	
	return (i);
}

void	print_in_base(int nb, char *base, int base_len)
{
	if (nb > base_len)
		print_in_base(nb / base_len, base, base_len);
	write(1, &base[nb % base_len], 1);
}


void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;
	long	nb;

	base_len = validate_length(base);
	if (base_len < 2)
		return ;

	nb = nbr;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	print_in_base(nb, base, base_len);
}


int main()
{
	int nbr = 500;
	
	char base[] = "01";

	ft_putnbr_base(nbr, base);

	return (0);
}
