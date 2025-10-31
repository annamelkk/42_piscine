/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:57:49 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/26 15:23:18 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

char	*ft_strtrim(char *str)
{
	int		i;
	int		j;
	int		k;
	int		trim_len;
	char	*trim;

	if (!str)
		return (NULL);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	j = ft_strlen(str) - 1;
	while (j >= 0 && (ft_isspace(str[j])))
		j--;
	if (i > j)
		return (ft_strdup(""));
	trim_len = j - i + 1;
	trim = (char *)malloc(trim_len + 1);
	if (!trim)
		return (NULL);
	k = 0;
	while (k < trim_len)
		trim[k++] = str[i++];
	trim[k] = '\0';
	return (trim);
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

char	*read_line(int fd)
{
	char	buffer[1000];
	int		i;

	i = 0;
	while (read(fd, &buffer[i], 1) > 0)
	{
		if (buffer[i] == '\n')
		{
			buffer[i + 1] = '\0';
			return (ft_strdup(buffer));
		}
		i++;
		if (i >= 999)
			break ;
	}
	if (i > 0)
	{
		buffer[i] = '\0';
		return (ft_strdup(buffer));
	}
	return (NULL);
}

int	ft_atoi_n(char *str, int n)
{
	int	value;
	int	i;

	value = 0;
	i = 0;
	while (i < n)
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	return (value);
}
