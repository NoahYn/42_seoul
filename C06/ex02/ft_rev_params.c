/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 20:21:48 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/09 23:52:29 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	len;

	argc--;
	while (argc > 0)
	{
		len = 0;
		while (argv[argc][len])
			len++;
		write(1, argv[argc], len);
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
