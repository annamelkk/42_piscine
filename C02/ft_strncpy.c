#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;

	while(i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	while(i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return dest;
}


int main()
{
	char source[] = "string Copy!";
	char destination[20];
	ft_strncpy(destination, source, 20);
	
	printf("The custom copied string: %s\n", destination);

	return 0;
}
