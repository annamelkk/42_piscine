/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:31:53 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/22 16:52:50 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (nb >= base_len)
		print_in_base(nb / base_len, base, base_len);
	write(1, &base[nb % base_len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = validate_length(base);
	if (base_len < 2)
		return ;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	print_in_base(nbr, base, base_len);
}
/*
int main()
{
	int nbr = -2147483648;
	char base[] = "0123456789";

	ft_putnbr_base(nbr, base);

	return (0);
}
*/
