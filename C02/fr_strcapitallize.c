#include <stdio.h>

int numerical(char c)
{
    return( c >= '0' && c <='9');
}
int uppercase(char c)
{
    return (c >= 'A' && c <= 'Z');
}
int lowercase(char c)
{
    return (c >= 'a' && c <= 'z');
}

char    *ft_strcapitalize(char  *str)
{
    int i = 0;
    int new_word = 1;
    while (str[i] != '\0')
    {
        if (new_word && lowercase(str[i]) )
        {
            str[i] -= 32;
            new_word = 0;
        }
        else if (!new_word && uppercase(str[i]) )
            str[i] += 32;
        else if (!new_word && lowercase(str[i]))
        {
            // already lowercase, do nothing
        }
        else if (!new_word && numerical(str[i]))
        {
            // digits inside a word, keep new_word = 0
        }
        else
            new_word = 1;
            i++;
    }
    
}


int main() {
    char c[] = "hi, how are you? 42words forty-two; fifty+and+one";
    ft_strcapitalize(c);
    printf("%s", c);
    return 0;
}
