/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:26:53 by sunyoon           #+#    #+#             */
/*   Updated: 2023/06/06 16:40:37 by sunyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // write getpid sleep usleep pause
#include <stdlib.h> // malloc free exit
#include <signal.h> // signal sigemptyset sigaddset sigaction kill
#include "ft_printf/ft_printf.h" // ft_printf libft

static void	ft_exit(const char *str)
{
	ft_printf("%s", str);
	exit(1);
}

static void	handler(int sig)
{
	static int	bit = 0;
	static char	c = 0;

	if (sig == SIGUSR1)
		c += (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (write(1, &c, 1) == -1)
			ft_exit("write error\n");
		c = 0;
		bit = 0;
	}
	return ;
}

int	ft_send(char *str, pid_t pid)
{
	static int		i = -1;
	unsigned int	bit;
	char			c;

	while (str[++i])
	{
		c = 0;
		bit = 0;
		while (bit < 8)
		{
			usleep(100);
			if ((1 << bit) & str[i])
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_exit("kill error\n");
				c += (1 << bit);
			}
			else
				if (kill(pid, SIGUSR2) == -1)
					ft_exit("kill error\n");
			++bit;
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	pid_t				pid;

	if (argc != 3)
		ft_exit("The number of argument should be 2\n");
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99998)
		ft_exit("Invalid pid\n");
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_exit("Sigaction error\n");
	ft_send(argv[2], pid);
	usleep(3000);
	return (0);
}
