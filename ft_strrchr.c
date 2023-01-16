/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:10:11 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/09 17:40:58 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (s[len])
		++len;
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)s + len);
		--len;
	}
	return (0);
}
