/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 13:40:34 by sunyoon           #+#    #+#             */
/*   Updated: 2022/09/09 21:31:45 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_skip_space(char *str)
{	
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

int	ft_neg_cnt(char *str, int i, int *neg_cnt)
{
	while (str[i] == '+' || str[i] == '-')
	{			
		if (str[i] == '-')
			(*neg_cnt)++;
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	neg_cnt;
	int	i;
	int	atoi;

	neg_cnt = 0;
	atoi = 0;
	i = ft_skip_space(str);
	i = ft_neg_cnt(str, i, &neg_cnt);
	while (str[i] >= '0' && str[i] <= '9')
	{
		atoi = 10 * atoi + str[i] - '0';
		i++;
	}
	if (neg_cnt % 2 == 1)
		atoi *= -1;
	return (atoi);
}
