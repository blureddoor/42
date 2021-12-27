#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int	i;
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_count(long num, int base)
{
	int i;
	i = 1;
	while (num >= base && ++i)
		num = num / base;
	return (i);
}

void	ft_putnum(long num, int base)
{
	char *str = "0123456789abcdef";
	if (num >= base)
		ft_putnum((num / base), base);
	write(1, &str[num % base], 1);
}

int		ft_printf(const char *format, ...)
{
	va_list list;
	char *str;
	long int num;
	int pos = 0, i = 0, space = 0, neg = 0, zero = 0, str_len = 0 , width = 0, dot = 0, range = 0, base = 0;
	va_start(list, format);

	while (format[pos])
	{
		if (format[pos] == '%' && ++pos)
		{
			num = 0, space = 0, neg = 0, zero = 0, str_len = 0, width = 0, dot = 0, range = 0, base = 0;
			while (format[pos] >= '0' && format[pos] <= '9')
				width = width * 10 + format[pos++] - 48;
			if (format[pos] == '.' && ++pos && ++dot)
				while (format[pos] >= '0' && format[pos] <= '9')
					range = range * 10 + format[pos++] - 48;
			if (format[pos] == 's')
			{
				if (!(str = va_arg(list, char*)))
					str = "(null)";
				str_len = ft_strlen(str);
			}
			else if (format[pos] == 'd')
			{
				if ((num = va_arg(list, int)) < 0 && ++neg)
					num = -num;
				str_len = ft_count(num, (base = 10));
			}
			else if (format[pos] == 'x')
				str_len = ft_count((num = va_arg(list, unsigned int)),
						(base = 16));
			if (dot && str_len > range && format[pos] =='s')
				str_len = range;
			if (dot && str_len < range && format[pos] !='s')
				zero = range - str_len;
			if (dot && !range && (format[pos] == 's' || !num))
				str_len = 0;
			space = width - str_len - neg - zero;
			while (space-- > 0 && ++i)
				write(1, " ", 1);
			if (neg > 0 && ++i)
				write(1, "-", 1);
			while (zero-- > 0 && ++i)
				write(1, "0", 1);
			if (format[pos] == 's')
				write(1, str, str_len);
			else if (str_len > 0)
				ft_putnum(num, base);
			i += str_len;
		}
		else if (++i)
			write(1, &format[pos], 1);
		pos++;
	}
	va_end(list);
	return (i);
}

/*
int main()
{
	printf("The color: %s\n", "blue");
	ft_printf("The color: %s\n", "blue");
    printf("First number:%d\n", 12345);
    ft_printf("First number:%d\n", 12345);
    printf("Second number:%4d\n", 25);
    ft_printf("Second number:%4d\n", 25);
    printf("Hexadecimal:%x\n", 255);
    ft_printf("Hexadecimal:%x\n", 255);
 }

int main()
{
    printf(":%s:\n", "Hello World!");
    ft_printf(":%s:\n", "Hello World!");
    printf(":%15s:\n", "Hello World!");
    ft_printf(":%15s:\n", "Hello World!");
    printf(":%.10s:\n", "Hello World!");
    ft_printf(":%.10s:\n", "Hello World!");
    printf(":%.15s:\n", "Hello World!");
    ft_printf(":%.15s:\n", "Hello World!");
    printf(":%15.10s:\n", "Hello World!");
    ft_printf(":%15.10s:\n", "Hello World!");
    printf(":%15.10s:\n", "Hello World!");
    ft_printf(":%15.10s:\n", "Hello World!");
    return (0);
}

int main ( void )
{
  printf ( "%5d\n", 123 );    
  ft_printf ( "%5d\n", 123 ); 
  printf ( "%d\n", 5, 123 ); 
  ft_printf ( "%d\n", 5, 123 );   
  printf ( "%x\n", 123U );     
  ft_printf ( "%x\n", 123U );  
  printf ( "%s\n", "Testing" );
  ft_printf ( "%s\n", "Testing");
  system("leaks a.out");
  return 0;
}

int main()
{
    printf("Create a new line\n");
    ft_printf("Create a new line\n");
    printf("Print a double quotes (\") within a string\n");
    ft_printf("Print a double quotes (\") within a string\n");
    printf("Print a single quotes (\') within a string\n");
    ft_printf("Print a single quotes (\') within a string\n");
    printf("Print a Backslash\\ within a string\n");
    ft_printf("Print a Backslash\\ within a string\n");
    printf("Using Backspace\b within a string\n");
    ft_printf("Using Backspace\b within a string\n");
    printf("Using\tTab within a string\n");
    ft_printf("Using\tTab within a string\n");
    system("leaks .out");
    return (0);
}

int main () {
   int ch;

   for( ch = 33 ; ch <= 127; ch++ ) {
      printf("ASCII value = %d, Character = %c\n", ch , ch );
   }
   for( ch = 33 ; ch <= 127; ch++ ) {
   ft_printf("ASCII value = %d, Character = %c\n", ch , ch );
   }
   system("leaks a.out");
   return(0);
}

int main()
{
   char str[20] = "fresh2refresh.com";
   int no = 150;
   printf("String is %s \n" , str);
   ft_printf("String is %s \n" , str);
   printf("Integer value is %d\n" , no);
   ft_printf("Integer value is %d\n" , no);
   printf("Hexadecimal value is %x \n", no);
   ft_printf("Hexadecimal value is %x \n", no);
   system("leaks a.out");
   return 0;
}

*/
