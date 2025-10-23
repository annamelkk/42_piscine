/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:22:33 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/22 18:24:35 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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
/*
int main()
{
	int n = 9;
	int p = 2;

	printf("%d", ft_iterative_power(n, p));
	return (0);
}
*/
