/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:33:01 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/08 12:51:12 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (0);
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (0);
	s += start;
	while (*s && len--)
		*substr++ = *s++;
	*substr = 0;
	return (substr);
}
