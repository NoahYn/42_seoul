#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_strnstr.c"
#include "ft_substr.c"

int main() 
{
	printf("%s\n", ft_substr("", 1, 1));
	ft_strnstr("abcdefgh", "abc", 3);
	system("leaks a.out");
}