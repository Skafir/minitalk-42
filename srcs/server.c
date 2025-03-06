/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skafir <skafir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:14:07 by skafir            #+#    #+#             */
/*   Updated: 2025/03/06 21:14:08 by skafir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int		bit = 0;
	static char		character = 0;
	static pid_t	client_pid;
	static char		*str = NULL;

	(void)context;
	if (info->si_pid)
		client_pid = info->si_pid;
	if (signal == SIGUSR1)
		character |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		handle_message((char)character, &str);
		bit = 0;
		character = 0;
	}
	kill(client_pid, SIGUSR1);
}

void	signal_(int signal, void *handler)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(signal, &sa, NULL) < 0)
	{
		ft_putstr_fd("Error : Sigaction\n", 1);
		exit(1);
	}
}

int	main(void)
{
	char	*client_pid;

	ft_putstr_fd("Server PID : ", 1);
	client_pid = ft_itoa(getpid());
	ft_putstr_fd(client_pid, 1);
	ft_putchar_fd('\n', 1);
	free(client_pid);
	signal_(SIGUSR1, handle_signal);
	signal_(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
