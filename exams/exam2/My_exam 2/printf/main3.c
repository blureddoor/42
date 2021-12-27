#include <stdio.h>

int     ft_printf(const char *format, ...);

int main()
{
    ft_printf("%0.2s\n", "toto");
    printf("%0.2s\n", "toto");
    ft_printf("Magic %s is %0.4d\n", "number", 42);
    printf("Magic %s is %0.4d\n", "number", 42);
    ft_printf("\nHexadecimal for %d is %x", 42, 42);
    printf("\nHexadecimal for %d is %x\n", 42, 42);

    ft_printf("\nMi test %10.10s %10.10s %10.10s ", "", "01345678954", NULL);
    printf("\nMi test %10.10s %10.10s %10.10s ", "", "01345678954", NULL);
    return (0);
}
