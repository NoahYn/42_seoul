/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subilee <subilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:11:00 by subilee           #+#    #+#             */
/*   Updated: 2022/09/04 11:11:21 by subilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_solvable(int *nums)
{
	int	i;
	int	sum;

	i = 0;
	while (i < 12)
	{
		sum = nums[i] + nums[i + 4];
		if (sum < 3 || sum > 6)
			return (0);
		i++;
		if (i % 4 == 0)
			i += 4;
	}
	return (1);
}

int	check_input(char *str, int *nums)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 31)
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			nums[j] = str[i] - '0';
			i++;
			j++;
			if (j == 16 && !str[i])
				return (1);
			if (str[i] == ' ')
				i++;
			else
				return (0);
		}
		else
			return (0);
	}
	return (0);
}
