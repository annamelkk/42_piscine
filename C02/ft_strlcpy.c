#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int src_len = 0;
    unsigned int i = 0;

    while (src[src_len])
        src_len++;

    if (size == 0)
        return (src_len);

    while (i + 1 < size && src[i])
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';

    return (src_len);
}

int main()
{
	char src[] = "Hello, world!";
	char dest[6];
	unsigned int len = ft_strlcpy(dest, src, sizeof(dest));

	printf("dest = \"%s\"\n", dest); // prints: "Hello"
	printf("src length = %u\n", len); // prints: 13
}
