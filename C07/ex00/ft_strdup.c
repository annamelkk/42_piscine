/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:06:40 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/27 15:13:07 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*new_string;

	i = 0;
	size = 0;
	if (src[i] == '\0')
		return (NULL);
	while (src[i])
	{
		size++;
		i++;
	}
	new_string = (char *)malloc(size + 1);
	if (!new_string)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new_string[i] = src[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

int main(void)
{
	char *original = "Hello world!";
	char *copy = ft_strdup(original);

	printf("Original: %s\n", original);
	printf("Copy: %s\n", copy);

	free(copy);
	return 0;
}

