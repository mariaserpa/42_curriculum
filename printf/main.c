#include <stdio.h>
#include "ft_printf.h"


int main() {
    int num = 42;
    char *str = "Hello, world!";
    void *ptr = &num;

	ft_printf(NULL);
	printf("\n");
	printf(NULL);
	printf("\n");
    ft_printf("Printing a character: %c", 'A');
	printf("\n");
    ft_printf("Printing a string: %s", str);
	printf("\n");
    ft_printf("Printing a decimal number: %d", num);
	printf("\n");
    ft_printf("Printing a pointer: %p", ptr);
	printf("\n");
    ft_printf("Printing an unsigned decimal number: %u", 12345);
	printf("\n");
    ft_printf("Printing a hexadecimal number: %x", 255);
	printf("\n");
	ft_printf(" %c %c %c ", '0', 0, '1');
	printf("\n");
	printf(" %c %c %c ", '0', 0, '1');
    return (0);
}
