#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return str;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] != '\0')
		{
			if (str[i + j] != to_find[j])
				break;
			j++;
		}
	if (to_find[j] == '\0')
		return (&str[i]);
	i++;
	}
	return NULL;
		
}


int main()
{
	char haystack[] = "hello world";
	char needle[]   = "lo";

	char *c = ft_strstr(haystack, needle);
	printf("%s", c);
}
