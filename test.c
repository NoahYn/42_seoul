#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"

int main()
{	
	char *s = "abcde";
	int a;
	
	a = printf("%s\n", s);
	printf("%d\n", a);
	a = ft_printf("%s\n", s);
	ft_printf("%d\n", a);
}