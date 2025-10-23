/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:47:22 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/16 17:17:53 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
int main()
{
	int a = 1;
	int b = 2;


	printf("Value of a - %d and value of b - %d before swapping \n", a, b);

	ft_swap(&a, &b);

	printf("Value of a - %d and value of b - %d before swapping", a, b);

	return (0);
}
*/
