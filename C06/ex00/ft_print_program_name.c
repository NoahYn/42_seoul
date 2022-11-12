/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:28:40 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/09 23:51:15 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	len;

	if (argc < 1)
		return (-1);
	len = 0;
	while (argv[0][len])
		len++;
	write(1, argv[0], len);
	write(1, "\n", 1);
	return (0);
}
