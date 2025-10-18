#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_length;
	unsigned int src_length;
	unsigned int i;

	dest_length = 0;
	src_length = 0;
	i = 0;
	while (dest[i] != '\0')
	{
		dest_length++;
		i++;
	}
	i = 0;
	while (src[i] != '\0')
	{
		src_length++;
		i++;
	}

	if (size <= dest_length)
		return (dest_length + src_length);

	i = 0;
	while (src[i] != '\0' && (dest_length + i) < size - 1)
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = '\0';
	return (dest_length + src_length);  
}

int main()
{
	char src[] = "heyllo";
	char dest[20] = "madame ";

	int num = ft_strlcat(dest, src, 20);
	
	
	printf("%s and %d", dest, num);
	return (0);
}
