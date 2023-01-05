/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:53:32 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/05 16:53:45 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include <string.h>

int main() {
	char hay[30] = "I am a boy";
	char needle[10] = "boy";
	int b = 'b';

	printf("%s\n", memchr(hay, b, 3));
	printf("%s\n", ft_memchr(hay, b, 3));
}