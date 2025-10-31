/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:17:58 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/28 14:44:35 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcpy(char *dest, char *src, int n)
{
	int	j;

	j = 0;
	while (src[j])
		dest[n++] = src[j++];
	return (n);
}

char	*ft_empty(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		k;
	int		i;
	int		length;
	char	*result;

	if (size == 0)
		return (ft_empty());
	length = 0;
	i = 0;
	k = 0;
	while (i < size)
		length += ft_strlen(strs[i++]);
	length += ft_strlen(sep) * (size - 1);
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		k = ft_strcpy(result, strs[i], k);
		if (i++ < size - 1)
			k = ft_strcpy(result, sep, k);
	}
	result[k] = '\0';
	return (result);
}
/*
int	main()
{
	char *string[] = {"foo", "boo"};
	printf("%s", ft_strjoin(2, string, ","));
	return (0);

}
*/
