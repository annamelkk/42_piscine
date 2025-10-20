#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int main()
{
	char c[] = "hello";
	printf("length: %d", ft_strlen(c));
	return (0);
}
