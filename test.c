#include <stdio.h>
#include "libftprintf.h"

void	check_return(int n1, int n2)
{
	if (n1 == n2)
		printf("\x1b[32m[Return OK]\x1b[39m\n");
	else
		printf("\x1b[31m[Return NG]\x1b[39m\n");

}

int main(void)
{
	int		n1;
	int		n2;
	char *str = "hello world";
	char *str2 = "goodbye";
	printf("---Test 1---\n");
	n1 = printf("[c:%c, s:%s, p:%p, d:%d, u:%u, x:%x, X:%X]",'c', str, str, -2147483648, 1500, 110985432, 129808);
	printf(" ret:%d\n", n1);
	n2 = ft_printf("[c:%c, s:%s, p:%p, d:%d, u:%u, x:%x, X:%X]",'c', str, str, -2147483648, 1500, 110985432, 129808);
	printf(" ret:%d\n", n2);
	check_return(n1, n2);

	printf("---Test 2---\n");
	n1 = printf("[c:%c, s:%s, p:%p, d:%d, u:%u, x:%x, X:%X]",'0', NULL, NULL, -2147483648, 0, 2147483647, 2147483647);
	printf(" ret:%d\n", n1);
	n2 = ft_printf("[c:%c, s:%s, p:%p, d:%d, u:%u, x:%x, X:%X]",'0', NULL, NULL, -2147483648, 0, 2147483647, 2147483647);
	printf(" ret:%d\n", n2);
	check_return(n1, n2);

	printf("---Test 3---\n");
	n1 = printf("[%10s, %11s, %12s]", str, str, str);
	printf(" ret:%d\n", n1);
	n2 = ft_printf("[%10s, %11s, %12s]", str, str, str);
	printf(" ret:%d\n", n2);
	check_return(n1, n2);

	printf("---Test 3---\n");
	n1 = printf("[%-10s, %-11s, %-12s]", str, str, str);
	printf(" ret:%d\n", n1);
	n2 = ft_printf("[%-10s, %-11s, %-12s]", str, str, str);
	printf(" ret:%d\n", n2);
	check_return(n1, n2);

	printf("---Test 4---\n");
	n1 = printf("[%010s, %011s, %013s]", str, str, str);
	printf(" ret:%d\n", n1);
	n2 = ft_printf("[%010s, %011s, %013s]", str, str, str);
	printf(" ret:%d\n", n2);
	check_return(n1, n2);

	printf("---Test 5---\n");
	n1 = printf("[%.4s, %.14s, %5.10s, %10.5s]", str, str, str, str);
	printf(" ret:%d\n", n1);
	n2 = ft_printf("[%.4s, %.14s, %5.10s, %10.5s]", str, str, str, str);
	printf(" ret:%d\n", n2);
	check_return(n1, n2);

	printf("---Test 6---\n");
	n1 = printf("[%*s, %*s, %*s]", -16, str2, 0, str2, 5, str2);
	printf(" ret:%d\n", n1);
	n2 = ft_printf("[%*s, %*s, %*s]", -16, str2, 0, str2, 5, str2);
	printf(" ret:%d\n", n2);
	check_return(n1, n2);

	printf("---Test 7---\n");
	n1 = printf("[%.*s, %.*s, %.*s]", 16, str, 0, str, 5, str);
	printf(" ret:%d\n", n1);
	n2 = ft_printf("[%.*s, %.*s, %.*s]", 16, str, 0, str, 5, str);
	printf(" ret:%d\n", n2);
	check_return(n1, n2);

	printf("---Test 8---\n");
	n1 = printf("[%*.*s, %0*.*s, %-*.*s]", 5, 16, str, 15, 0, str, -2, 5, str);
	printf(" ret:%d\n", n1);
	n2 = ft_printf("[%*.*s, %0*.*s, %-*.*s]", 5, 16, str, 15, 0, str, -2, 5, str);
	printf(" ret:%d\n", n2);
	check_return(n1, n2);
}
