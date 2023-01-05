#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "ft_memchr.c"

int main() {
	char hay[30] = "I am a boy";
	char needle[10] = "boy";
	int b = 'b';

	printf("%s\n", memchr(hay, b, 3));
	printf("%s\n", ft_memchr(hay, b, 3));
}