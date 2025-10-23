/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:34:26 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/22 16:55:29 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <unistd.h>

int	validate_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	n;

	base_len = validate_base(base);
	if (base_len == 0)
		return ;
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= base_len)
		ft_putnbr_base(n / base_len, base);
	write(1, &base[n % base_len], 1);
}

int	conversion(int nb, int base_len, int sign)
{
	int	converted;
	int	multiplier;

	if (nb < 0)
		nb = -nb;
	if (nb == 0)
		return (0);
	converted = 0;
	multiplier = 1;
	while (nb > 0)
	{
		converted = converted + (nb % base_len) * multiplier;
		nb /= base_len;
		multiplier *= 10;
	}
	if (sign < 0)
		return (-converted);
	return (converted);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	i;
	int	final_num;

	if (validate_base(base) == 0)
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	final_num = conversion(result * sign, validate_base(base), sign);
	return (final_num);
}
/*
int main()
{
	char	c[] = "--+---3ab0";
	printf("%d", ft_atoi_base(c, "01"));
	return (0);
}
*/
