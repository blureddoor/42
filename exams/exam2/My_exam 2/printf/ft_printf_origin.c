#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

size_t  ft_strlen(char *s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

int     ft_n_len(long long n, int base_len)
{
    int i = 1;
    while (n >= base_len || n <= -base_len)
    {
        n = n / base_len;
        i++;
    }
    return (i);
}

void    ft_put_n(long long n, int base_len, char *base)
{
    if (n >= base_len)
        ft_put_n(n / base_len, base_len, base);
    write (1, &base[n % base_len], 1);
}

int     ft_printf(const char *format, ...)
{
    va_list list;
    char    *str, *s, *base;
    long    num;
    int     w = 0, p = 0, bolp = 0, n = 0, base_len, len = 0, neg = 0, spc = 0, zero = 0;
    va_start(list, format);
    str = (char *)format;
    while (*str != '\0')
    {
        if (*str == '%')
        {
            str++;
            w = 0, p = 0, bolp = 0, n = 0, neg = 0, spc = 0, zero = 0;
            while (*str >= '0' && *str <= '9')
            {
                w = w * 10 + (*str - 48);
                str++;
            }
            if (*str == '.')
            {
                str++;
                while (*str >= '0' && *str <= '9')
                {
                    p = p * 10 + (*str - 48);
                    str++;
                }
                bolp = 1;
            }
            if (*str == 's')
            {
                s = va_arg(list, char *);
                if (!s)
                    s = "(null)";
                n = ft_strlen(s);
            }
            if (*str == 'x')
            {
                num = va_arg(list, unsigned);
                base = "0123456789abcdef";
                base_len = 16;
                n = ft_n_len(num, base_len);
            }
            if (*str == 'd')
            {
                num = va_arg(list, int);
                base = "0123456789";
                base_len = 10;
                if (num < 0)
                {
                    num = num * -1;
                    neg = 1;
                }
                n = ft_n_len(num, base_len) + neg;
            }
            if (bolp == 1 && p >= n && *str != 's')
                zero = p - n + neg;
            else if (bolp == 1 && p < n && *str == 's')
                n = p;
            else if (bolp == 1 && p == 0 && (*str == 's' || num == 0))
                n = 0;
            spc = w - n - zero;
            while (spc-- > 0)
            {
                write (1, " ", 1);
                len++;
            }
            if (neg == 1)
                write (1, "-", 1);
            while (zero-- > 0)
            {
                write (1, "0", 1);
                len++;
            }
            if (*str == 's')
                write (1, s, n);
            else if (n > 0)
                ft_put_n(num, base_len, base);
            len += n;
            str++;
        }
        else
        {
            write (1, str, 1);
            str++;
            len++;
        }   
    }
    return (len);
}