#include <stdlib.h>
#include "ft_itoa.c"
#include <assert.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>

int main()
{
	int n = -20;
	int b = -100;
	printf("%s\n", ft_itoa(n));
	printf("%s\n", ft_itoa(b));
}