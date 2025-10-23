/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:38:08 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/19 11:43:23 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int main() {
	char str1[] = "123567890aaaaaaaaaaa";
	
	char str2[] = "1234567890";
	
	int result;
	
	printf("Original:");
	printf("\n%s",str1);
	printf("\n%s",str2);
	result = ft_strncmp(str1, str2, 3);
	if( result < 0 )
	printf( "\nFirst is less than second.\n" );
	else if( result == 0 )
	printf( "\nFirst is equal to second.\n" );
	else
	printf( "\nFirst is greater than second.\n" );
	return 0;
}
*/
