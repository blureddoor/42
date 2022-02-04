#include <unistd.h>
#include <stdio.h>



char	*ft_strncat(char *dest, char *src, int nb)
{
  int d_length;
  int i;
  
  d_length = -1;
  while (dest[++d_length]);
  
  i = 0;
  while (i < nb)
  {
    dest[d_length] = src[i];
    i++;
    d_length++;
  }
  dest[d_length] = '\0';

  return (dest);
}


int main()
{
 char str[] = "sdfsd";
 char to_find[] = "asdf";
 int n = 2;
 
 printf("%s", ft_strncat(str, to_find, 2 ));
 
 return(0);
}
