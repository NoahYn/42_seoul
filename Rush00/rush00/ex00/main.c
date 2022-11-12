/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoonpa <jihoonpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:17:03 by jahlee            #+#    #+#             */
/*   Updated: 2022/08/28 20:45:16 by jihoonpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	rush(int x, int y);

int	main(int argc, char **argv)
{
	int	num[2];
	int	i;

	num[0] = 0;
	num[1] = 0;
	if (argc != 3 || argv[1][0] == '-' || argv[2][0] == '-')
	{
		write(2, "Wrong Usage", 11);
		return (0);
	}
	i = 0;
	while (argv[1][i] >= '0' && argv[1][i] <= '9')
	{
		num[0] = num[0] * 10 + (argv[1][i] - '0');
		i++;
	}
	i = 0;
	while (argv[2][i] >= '0' && argv[2][i] <= '9')
	{
		num[1] = num[1] * 10 + (argv[2][i] - '0');
		i++;
	}
	rush(num[0], num[1]);
	return (0);
}
