#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
		return (0);
		
}
/*
int main() {
	char str1[] = "124567890aaaaaaaaaaa";
	
	char str2[] = "1234567890";
	
	int result;
	
	printf("Original:");
	printf("\n%s",str1);
	printf("\n%s",str2);
	result = ft_strncmp(str1, str2, 3);
	if( result < 0 )
	printf( "\nFirst is less than second.\n" );
	else if( result == 0 )
	printf( "\nFirst is equal to second.\n" );
	else
	printf( "\nFirst is greater than second.\n" );
	return 0;
}
*/
