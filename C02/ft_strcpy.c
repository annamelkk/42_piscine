#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;

	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return dest;
}


int main()
{
	char source[] = "string Copy!";
	char destination[20];
	ft_strcpy(destination, source);
	
	printf("The custom copied string: %s\n", destination);

	return 0;
}
