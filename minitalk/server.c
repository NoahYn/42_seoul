/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunyoon <sunyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:30:38 by sunyoon           #+#    #+#             */
/*   Updated: 2023/06/06 16:32:30 by sunyoon          ###   ########.fr       */
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

static void	handler(int sig, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	c = 0;

	(void)context;
	(void)info;
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

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_exit("Sigaction error\n");
	pid = getpid();
	ft_printf("Server pid : %d\n", pid);
	while (1)
		pause();
	return (0);
}
