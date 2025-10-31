/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:25:34 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/24 13:36:05 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;
	int	square;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (0);
	i = 1;
	while (i * i <= nb)
	{
		square = i * i;
		if (square == nb)
			return (i);
		i++;
	}
	return (0);
}
/*
int main()
{
	int m = 81;
	
	printf("%d", ft_sqrt(m));
	return (0);
}
*/
