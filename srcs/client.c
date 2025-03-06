/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skafir <skafir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:13:48 by skafir            #+#    #+#             */
/*   Updated: 2025/03/06 21:15:30 by skafir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_confirmed = 0;

void	confirmation_handler(int signal)
{
	(void)signal;
	g_confirmed = 1;
}

void	send_character(pid_t server_pid, char character)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_confirmed = 0;
		if (character & (1 << (7 - bit)))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		++bit;
		while (!g_confirmed)
			usleep(100);
	}
}

void	send_message(pid_t server_pid, char *message)
{
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = confirmation_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	while (*message)
		send_character(server_pid, *message++);
	send_character(server_pid, '\0');
	exit(0);
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*message;

	if (argc != 3)
	{
		ft_putstr_fd("Usage : ./client [server_pid] [message]\n", 1);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0 || kill(server_pid, 0))
	{
		ft_putstr_fd("Invalid PID\n", 1);
		return (1);
	}
	message = argv[2];
	send_message(server_pid, message);
	return (0);
}
