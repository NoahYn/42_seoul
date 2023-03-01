/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:57:26 by sunyoon           #+#    #+#             */
/*   Updated: 2023/03/01 21:42:50 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "get_next_line.h"

int	main(void)
{
	int		fd, fd2;
	char	*s;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd2));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd2));		
	
	if (BUFFER_SIZE > 100) {
		char *temp;
		do
		{
			temp = get_next_line(fd);
			free(temp);
		} while (temp != NULL);
	}
	printf ("%s", get_next_line(fd));
	close(fd);
	printf ("%s", get_next_line(fd2));		

	fd = open("test.txt", O_RDONLY);
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd2));		
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));		
	printf ("%s", get_next_line(fd2));
	printf ("%s", get_next_line(fd2));		
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));		
	
}
