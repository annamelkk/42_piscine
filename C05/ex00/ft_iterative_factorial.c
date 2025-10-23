/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:19:50 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/22 18:20:46 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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
/*
int main()
{
	int m = 5;
	
	printf("%d", ft_iterative_factorial(m));
	return (0);
}
*/
