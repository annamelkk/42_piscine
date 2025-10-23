/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:26:34 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/14 17:34:58 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (!(b == 0))
	{
		*div = a / b;
		*mod = a % b;
	}
}
/*
int	main()
{
	int a = 10;
	int b = 5;

	int q, p;

	ft_div_mod(a, b, &q, &p);

	printf("1st number: %d \n\n", a);
	printf("2nd number: %d \n\n", b);

	printf("Result: %d \n", q);
	printf("Remainder %d", p);
	
	return (0);
}
*/
