#include <stdio.h>
#include <stdarg.h>

int	ft_printf(char const *format, ...);

int	main(void)
{

	ft_printf("Simple test\n");

	printf("Original:\n");
	printf("");
	printf("\nMío:\n");
	ft_printf("");
	printf("\n");

	printf("Original:\n");
	printf("Hola mundo!");
	printf("\nMío:\n");
	ft_printf("Hola mundo!");
	printf("\n");

	ft_printf("--Format---");
	ft_printf("\n");
	printf("Original:\n");
	printf("%d", 0);
	printf("\nMío:\n");
	ft_printf("%d", 0);
	printf("\n");

	printf("Original:\n");
	printf("%d", 42);
	printf("\nMío:\n");
	ft_printf("%d", 42);
	printf("\n");

	printf("Original:\n");
	printf("%d", 1);
	printf("\nMío:\n");
	ft_printf("%d", 1);
	printf("\n");
	
	printf("Original:\n");
	printf("%d", 5454);
	printf("\nMío:\n");
	ft_printf("%d", 5454);
	printf("\n");
	
	printf("Original:\n");
	printf("%d", (int)2147483647);
	printf("\nMío:\n");
	ft_printf("%d", (int)2147483647);
	printf("\n");
	
	printf("Original:\n");
	printf("%d", (int)-2147483648);
	printf("\nMío:\n");
	ft_printf("%d", (int)-2147483648);
	printf("\n");
	
	printf("Original:\n");
	printf("%ld", -2147483649);
	printf("\nMío:\n");
	ft_printf("%d", (int)-2147483649);
	printf("\n");
	
	ft_printf("\n");
	printf("Original:\n");
	printf("%x", 0);
	printf("\nMío:\n");
	ft_printf("%x", 0);
	printf("\n");
	
	printf("Original:\n");
	printf("%x", 42);
	printf("\nMío:\n");
	ft_printf("%x", 42);
	printf("\n");
	
	printf("Original:\n");
	printf("%x", 1);
	printf("\nMío:\n");
	ft_printf("%x", 1);
	printf("\n");
	
	printf("Original:\n");
	printf("%x", 5454);
	printf("\nMío:\n");
	ft_printf("%x", 5454);
	printf("\n");
	
	printf("Original:\n");
	printf("%x", (int)2147483647);
	printf("\nMío:\n");
	ft_printf("%x", (int)2147483647);
	printf("\n");
	
	printf("Original:\n");
	printf("%x", (int)2147483648);
	printf("\nMío:\n");
	ft_printf("%x", (int)2147483648);
	printf("\n");
	
	printf("Original:\n");
	printf("%x", (int)-2147483648);
	printf("\nMío:\n");
	ft_printf("%x", (int)-2147483648);
	printf("\n");
	
	printf("Original:\n");
	printf("%x", (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("%x", (int)-2147483649);
	printf("\n");
	
	ft_printf("--String---");
	ft_printf("\n");

	printf("Original:\n");
	printf("%s", "");
	printf("\nMío:\n");
	ft_printf("%s", "");
	printf("\n");

	printf("Original:\n");
	printf("%s", "toto");
	printf("\nMío:\n");
	ft_printf("%s", "toto");
	printf("\n");
	
	printf("Original:\n");
	printf("%s", "wiurwuyrhwrywuier");
	printf("\nMío:\n");
	ft_printf("%s", "wiurwuyrhwrywuier");
	printf("\n");
	
	printf("Original:\n");
	printf("%s", NULL);
	printf("\nMío:\n");
	ft_printf("%s", NULL);
	printf("\n");
	
	printf("Original:\n");
	printf("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	printf("\nMío:\n");
	ft_printf("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	printf("\n");
	
	
	ft_printf("\n--Mixed---\n");

	printf("Original:\n");
	printf("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	printf("\nMío:\n");
	ft_printf("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	printf("\n");

	printf("Original:\n");
	printf("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	printf("\nMío:\n");
	ft_printf("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	printf("\n");

	printf("Original:\n");
	printf("\n");
	printf("\nMío:\n");
	ft_printf("\n");
	printf("\n");

	printf("Original:\n");
	printf("%s%s%s%s\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	printf("\nMío:\n");
	ft_printf("%s%s%s%s\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	printf("\n");

	printf("Original:\n");
	printf("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	printf("\nMío:\n");
	ft_printf("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	printf("\n");

	ft_printf("--1 Flag--\n");

	printf("Original:\n");
	printf("d0w %0d %0d %0d %0d %0d %0d %0d %0d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("d0w %0d %0d %0d %0d %0d %0d %0d %0d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");
	
	printf("Original:\n");
	printf("d4w %4d %4d %4d %4d %4d %4d %4d %4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("d4w %4d %4d %4d %4d %4d %4d %4d %4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");
	
	printf("Original:\n");
	printf("d10w %10d %10d %10d %10d %10d %10d %10d %10d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("d10w %10d %10d %10d %10d %10d %10d %10d %10d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("d0p %.0d %.0d %.0d %.0d %.0d %.0d %.0d %.0d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("d0p %.0d %.0d %.0d %.0d %.0d %.0d %.0d %.0d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");
	
	
	printf("Original:\n");
	printf("d4p %.4d %.4d %.4d %.4d %.4d %.4d %.4d %.4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("d4p %.4d %.4d %.4d %.4d %.4d %.4d %.4d %.4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("d10p %.10d %.10d %.10d %.10d %.10d %.10d %.10d %.10d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("d10p %.10d %.10d %.10d %.10d %.10d %.10d %.10d %.10d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");	
	
	printf("Original:\n");
	printf("x0w %0x %0x %0x %0x %0x %0x %0x %0x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("x0w %0x %0x %0x %0x %0x %0x %0x %0x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");	

	printf("Original:\n");
	printf("x4w %4x %4x %4x %4x %4x %4x %4x %4x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("x4w %4x %4x %4x %4x %4x %4x %4x %4x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");	

	printf("Original:\n");
	printf("x10w %10x %10x %10x %10x %10x %10x %10x %10x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("x10w %10x %10x %10x %10x %10x %10x %10x %10x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("x0p %.0x %.0x %.0x %.0x %.0x %.0x %.0x %.0x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("x0p %.0x %.0x %.0x %.0x %.0x %.0x %.0x %.0x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("x4p %.4x %.4x %.4x %.4x %.4x %.4x %.4x %.4x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("x4p %.4x %.4x %.4x %.4x %.4x %.4x %.4x %.4x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("x10p %.10x %.10x %.10x %.10x %.10x %.10x %.10x %.10x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("x10p %.10x %.10x %.10x %.10x %.10x %.10x %.10x %.10x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("s0p ~%.0s` ~%.0s` ~%.0s` ~%.0s` ~%.0s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\nMío:\n");
	ft_printf("s0p ~%.0s` ~%.0s` ~%.0s` ~%.0s` ~%.0s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\n");

	printf("Original:\n");
	printf("s4w ~%4s` ~%4s` ~%4s` ~%4s` ~%4s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\nMío:\n");
	ft_printf("s4w ~%4s` ~%4s` ~%4s` ~%4s` ~%4s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\n");

	printf("Original:\n");
	printf("s4w ~%4s` ~%4s` ~%4s` ~%4s` ~%4s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\nMío:\n");
	ft_printf("s4w ~%4s` ~%4s` ~%4s` ~%4s` ~%4s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\n");

	printf("Original:\n");
	printf("s4p ~%.4s` ~%.4s` ~%.4s` ~%.4s` ~%.4s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\nMío:\n");
	ft_printf("s4p ~%.4s` ~%.4s` ~%.4s` ~%.4s` ~%.4s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\n");

	printf("Original:\n");
	printf("s10w ~%10s` ~%10s` ~%10s` ~%10s` ~%10s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\nMío:\n");
	ft_printf("s10w ~%10s` ~%10s` ~%10s` ~%10s` ~%10s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\n");

	printf("Original:\n");
	printf("s10p ~%.10s` ~%.10s` ~%.10s` ~%.10s` ~%.10s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\nMío:\n");
	ft_printf("s10p ~%.10s` ~%.10s` ~%.10s` ~%.10s` ~%.10s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\n");

	ft_printf("--2 Flags--\n");

	printf("Original:\n");
	printf("d0w0p %0.0d %0.0d %0.0d %0.0d %0.0d %0.0d %0.0d %0.0d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("d0w0p %0.0d %0.0d %0.0d %0.0d %0.0d %0.0d %0.0d %0.0d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("x0w0p %0.0x %0.0x %0.0x %0.0x %0.0x %0.0x %0.0x %0.0x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("x0w0p %0.0x %0.0x %0.0x %0.0x %0.0x %0.0x %0.0x %0.0x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	ft_printf("--Precision--\n");

	printf("Original:\n");
	printf("d0w4p %0.4d %0.4d %0.4d %0.4d %0.4d %0.4d %0.4d %0.4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("d0w4p %0.4d %0.4d %0.4d %0.4d %0.4d %0.4d %0.4d %0.4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("d0w10p %0.10d %0.10d %0.10d %0.10d %0.10d %0.10d %0.10d %0.10d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("d0w10p %0.10d %0.10d %0.10d %0.10d %0.10d %0.10d %0.10d %0.10d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("x0w4p %0.4x %0.4x %0.4x %0.4x %0.4x %0.4x %0.4x %0.4x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("x0w4p %0.4x %0.4x %0.4x %0.4x %0.4x %0.4x %0.4x %0.4x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("x0w10p %0.10x %0.10x %0.10x %0.10x %0.10x %0.10x %0.10x %0.10x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("x0w10p %0.10x %0.10x %0.10x %0.10x %0.10x %0.10x %0.10x %0.10x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	ft_printf("--Width--\n");

	printf("Original:\n");
	printf("d4w0p %4.0d %4.0d %4.0d %4.0d %4.0d %4.0d %4.0d %4.0d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("d4w0p %4.0d %4.0d %4.0d %4.0d %4.0d %4.0d %4.0d %4.0d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("d10w0p %10.0d %10.0d %10.0d %10.0d %10.0d %10.0d %10.0d %10.0d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("d10w0p %10.0d %10.0d %10.0d %10.0d %10.0d %10.0d %10.0d %10.0d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("x4w0p %4.0x %4.0x %4.0x %4.0x %4.0x %4.0x %4.0x %4.0x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("x4w0p %4.0x %4.0x %4.0x %4.0x %4.0x %4.0x %4.0x %4.0x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("x10w0p %10.0x %10.0x %10.0x %10.0x %10.0x %10.0x %10.0x %10.0x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("x10w0p %10.0x %10.0x %10.0x %10.0x %10.0x %10.0x %10.0x %10.0x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("s4w0p ~%4.s` ~%4.s` ~%4.s` ~%4.s` ~%4.s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\nMío:\n");
	ft_printf("s4w0p ~%4.s` ~%4.s` ~%4.s` ~%4.s` ~%4.s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\n");

	printf("Original:\n");
	printf("s10w0p ~%10.0s` ~%10.0s` ~%10.0s` ~%10.0s` ~%10.0s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\nMío:\n");
	ft_printf("s10w0p ~%10.0s` ~%10.0s` ~%10.0s` ~%10.0s` ~%10.0s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\n");

	ft_printf("--Width and Precision--\n");

	printf("Original:\n");
	printf("d10w4p %10.4d %10.4d %10.4d %10.4d %10.4d %10.4d %10.4d %10.4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("d10w4p %10.4d %10.4d %10.4d %10.4d %10.4d %10.4d %10.4d %10.4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("d10w10p %10.10d %10.10d %10.10d %10.10d %10.10d %10.10d %10.10d %10.10d\n", 0, 1, 42, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("d10w10p %10.10d %10.10d %10.10d %10.10d %10.10d %10.10d %10.10d %10.10d\n", 0, 1, 42, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("d4w4p %4.4d %4.4d %4.4d %4.4d %4.4d %4.4d %4.4d %4.4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("d4w4p %4.4d %4.4d %4.4d %4.4d %4.4d %4.4d %4.4d %4.4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("d4w10p %4.10d %4.10d %4.10d %4.10d %4.10d %4.10d %4.10d %4.10d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("d4w10p %4.10d %4.10d %4.10d %4.10d %4.10d %4.10d %4.10d %4.10d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("x10w4p %10.4x %10.4x %10.4x %10.4x %10.4x %10.4x %10.4x %10.4x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("x10w4p %10.4x %10.4x %10.4x %10.4x %10.4x %10.4x %10.4x %10.4x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("x10w10p %10.10x %10.10x %10.10x %10.10x %10.10x %10.10x %10.10x %10.10x\n", 0, 1, 42, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("x10w10p %10.10x %10.10x %10.10x %10.10x %10.10x %10.10x %10.10x %10.10x\n", 0, 1, 42, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("x4w4p %4.4x %4.4x %4.4x %4.4x %4.4x %4.4x %4.4x %4.4x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("x4w4p %4.4x %4.4x %4.4x %4.4x %4.4x %4.4x %4.4x %4.4x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("x4w10p %4.10x %4.10x %4.10x %4.10x %4.10x %4.10x %4.10x %4.10x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\nMío:\n");
	ft_printf("x4w10p %4.10x %4.10x %4.10x %4.10x %4.10x %4.10x %4.10x %4.10x\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("\n");

	printf("Original:\n");
	printf("s10w4p ~%10.4s` ~%10.4s` ~%10.4s` ~%10.4s` ~%10.4s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\nMío:\n");
	ft_printf("s10w4p ~%10.4s` ~%10.4s` ~%10.4s` ~%10.4s` ~%10.4s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\n");

	printf("Original:\n");
	printf("s10w10p ~%10.10s` ~%10.10s` ~%10.10s` ~%10.10s` ~%10.10s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\nMío:\n");
	ft_printf("s10w10p ~%10.10s` ~%10.10s` ~%10.10s` ~%10.10s` ~%10.10s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\n");

	printf("Original:\n");
	printf("s4w4p ~%4.4s` ~%4.4s` ~%4.4s` ~%4.4s` ~%4.4s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\nMío:\n");
	ft_printf("s4w4p ~%4.4s` ~%4.4s` ~%4.4s` ~%4.4s` ~%4.4s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\n");

	printf("Original:\n");
	printf("s4w10p ~%10.10s` ~%10.10s` ~%10.10s` ~%10.10s` ~%10.10s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\nMío:\n");
	ft_printf("s4w10p ~%10.10s` ~%10.10s` ~%10.10s` ~%10.10s` ~%10.10s`\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("\n");

	return (0);
}
