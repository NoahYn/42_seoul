#include "libft.h"

int ft_pow(int a, int b)
{
	int	c;

	c = 1;
	while (b > 1)
	{
		if (b % 2 == 1)
		{
			b--;
			c *= a;
		}
		a *= a;
		b /= 2;
	}
	return (a * c);
}