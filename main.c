/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:57:26 by sunyoon           #+#    #+#             */
/*   Updated: 2023/03/04 20:32:20 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*name = "test.txt";
//	char	*s;

	fd = open(name, O_RDONLY);
//	fd2 = open("test2.txt", O_RDONLY);
	printf ("1 %s", get_next_line(fd));
	printf ("2 %s", get_next_line(fd));
	printf ("3 %s", get_next_line(fd));
	close(fd);
	fd = open(name, O_RDONLY);
	printf ("4 %s", get_next_line(fd));		
	printf ("5 %s", get_next_line(fd));		
	printf ("6 %s", get_next_line(fd));		
	printf ("7 %s", get_next_line(fd));		
	printf ("8 %s", get_next_line(fd));		
/*	
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
*/	
}
