/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:23:14 by frnavarr          #+#    #+#             */
/*   Updated: 2025/05/06 16:42:11 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#define ENDOFMESSAGE '\n'

void	ack_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Received 1\n");
	else if (signal == SIGUSR2)
		ft_printf("Received 0\n");
}

void	send_signal(int pid, char SMS)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (SMS & (1 << i))
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
	i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
	{
		write(2, "Usage: ./client_bonus <PID> <message>\n", 38);
		return (1);
	}
	signal(SIGUSR1, ack_handler);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(2, "Invalid PID\n", 12);
		return (1);
	}
	i = 0;
	while (argv[2][i])
	{
		send_signal(pid, argv[2][i]);
		i++;
	}
	send_signal(pid, ENDOFMESSAGE);
	ft_printf("\n%i characters sent\n", i);
	return (0);
}
