#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

size_t  ft_strlen(char *s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

int     ft_num_len(long long n, int base_len)
{
    int i = 1;
    while (n >= base_len || n <= -base_len)
    {
        n = n / base_len;
        i++;
    }
    return (i); 
}

void    ft_put_num(long long n, int base_len, char *base)
{
    if (n >= base_len)
        ft_put_num(n / base_len, base_len, base);
    write (1, &base[n % base_len], 1);
}

int     ft_printf(const char *format, ...)
{
    va_list    list;
    char       *str, *s, *base;
    long       num;
    int        width = 0, prec = 0, bolpre = 0, n = 0, base_len, neg = 0, leng = 0, space = 0, zeros = 0;
    va_start(list, format);
    str = (char *)format;
     while (*str != '\0')
    {
         if (*str == '%')
        {
            str++;
            width = 0, prec = 0, bolpre = 0, n = 0, neg = 0, space = 0, zeros = 0;
            while (*str >= '0' && *str <= '9')
            {
                width = width * 10 + (*str - 48);
                str++;
            }
            if (*str == '.')
            {
                str++;
                while (*str >= '0' && *str <= '9')
                {
                    prec = prec * 10 + (*str - 48);
                    str++;
                }
                bolpre = 1;
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
                n = ft_num_len(num, base_len);
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
                n = ft_num_len(num, base_len) + neg;
            }
            if (bolpre == 1 && prec >= n && *str != 's')
                zeros = prec - n + neg;
            else if (bolpre == 1 && prec < n && *str == 's')
                n = prec;
            else if (bolpre == 1 && prec == 0 && (*str == 's' || num == 0))
                n = 0;
            space = width - n - zeros;
            while (space-- > 0)
            {
                write (1, " ", 1);
                leng++;
            }
            if (neg == 1)
                write (1, "-", 1);
            while (zeros-- > 0)
            {
                write (1, "0", 1);
                leng++;
            }
            if (*str == 's')
                write (1, s, n);
            else if (n > 0)
                ft_put_num(num, base_len, base);
            leng += n;
            str++;
        }
        else
        {
            write (1, str, 1);
            str++;
            leng++;
        }
    }
    return (leng);
}