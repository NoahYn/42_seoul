/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:53:33 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/04 12:42:30 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 'a' - 'A';
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	flag;

	ft_strlowcase(str);
	i = 0;
	flag = 1;
	while (str[i])
	{
		if (flag == 1 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] + 'A' - 'a';
			flag = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			flag = 0;
		else if (flag == 0 && (str[i] < 'a' || str[i] > 'z'))
			flag = 1;
		i++;
	}
	return (str);
}
