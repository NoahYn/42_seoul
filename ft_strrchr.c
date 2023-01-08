/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:10:11 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/08 12:31:19 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	ri;

	ri = 0;
	while (s[ri])
		++ri;
	while (s[ri])
	{
		if (s[ri] == (char)c)
			return ((char *)s + ri);
		--ri;
	}
	return (0);
}
