/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:10:11 by sunyoon           #+#    #+#             */
/*   Updated: 2023/01/02 19:13:16 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	last;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			last = i;
		i++;
	}
	if (i != 0)
		return (s + i);
	else
		return (0);
}
