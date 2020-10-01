/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:35:55 by marvin            #+#    #+#             */
/*   Updated: 2020/09/30 19:29:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	my_printf(const char *src, ...);
int	ft_strlen(const char *str);
char	*ft_itoa_base(long int n, char *base);
char	*ft_ultoa_base(unsigned long long n, char *base);

int main(void)

{
    int *ptr;
    int a;
    char *str;

    ptr = &a;
    str = " ABC D587-ghettyo";

    my_printf("string:%s\n", "-&¬Leo");
    printf("string:%s\n", "-&¬Leo");
    my_printf("int:%i\n", 32);
    printf("int:%i\n", 32);
    my_printf("decimal:%d\n", -2147847);
    printf("decimal:%d\n", -2147847);
    printf("decimal:%d\n", 2147847);
    my_printf("decimal:%d\n", 2147847);
    my_printf("character:%c\n", 'k');
    printf("character:%c\n", 'k');
    my_printf("puntero a int:%p\n", ptr);
    printf("puntero a int:%p\n", ptr);
    my_printf("puntero a str:%p\n", str);
    printf("puntero a str:%p\n", str);
    my_printf("Unsigned value:%u\n", 1250);
    printf("Unsigned value:%u\n", 1250);
    my_printf("Unsigned value:%u\n", -1250);
    printf("Unsigned value:%u\n", -1250);
    my_printf("hexadecimal:%x\n", 529496730);
    printf("hexadecimal:%x\n", 529496730);
    my_printf("hexadecimal:%x\n", -529496730);
    printf("hexadecimal:%x\n", -529496730);
    my_printf("unsigned hexadecimal:%X\n", 34387584);
    printf("unsigned hexadecimal:%X\n", 34387584);
    my_printf("unsigned hexadecimal:%X\n", -34387584);
    printf("unsigned hexadecimal:%X\n", -34387584);
    my_printf("Just print the percentage sign:%%\n\n");
    printf("Just print the percentage sign:%%\n");
    my_printf("%d", ft_strlen(str));
}
