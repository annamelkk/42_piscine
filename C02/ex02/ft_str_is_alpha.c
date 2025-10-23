/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:12:47 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/19 10:43:57 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	is_lower;
	int	is_upper;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		is_lower = (str[i] >= 'a' && str[i] <= 'z');
		is_upper = (str[i] >= 'A' && str[i] <= 'Z');
		if (!(is_lower || is_upper))
			return (0);
		i++;
	}
	return (1);
}
/*
int main()
{
    printf("%d\n", ft_str_is_alpha("Hel\nlo"));   
    return 0;
}
*/
