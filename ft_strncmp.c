/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:13:58 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/05 15:37:25 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && n--)
		if (*s1++ != *s2++)
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
	if (n)
		return (0);
	else
		return (*((unsigned char *)s1) - *((unsigned char *)s2));
}
