/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelkony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:57:49 by amelkony          #+#    #+#             */
/*   Updated: 2025/10/25 16:57:00 by amelkony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
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
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	j = ft_strlen(str) - 1;
	while (j >= 0 && str[j] == ' ' || (str[j] >= 9 && str[j] <= 13))
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
