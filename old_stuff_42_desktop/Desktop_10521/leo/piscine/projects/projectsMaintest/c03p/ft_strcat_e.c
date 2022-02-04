#include "stdio.h"


char	*ft_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	
	while(dest[i] != '\0')
		i++;
	
	while(src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	
	dest[i] = '\0';
	
	return (dest);
}

int main(void) {
    
    char dest[10] = "abc";
    char src[] = "def";
	
	ft_strcat(dest, src);
    printf("%s\n", dest);
    return 0;
}
