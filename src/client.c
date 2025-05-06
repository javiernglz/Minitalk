/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:14:22 by frnavarr          #+#    #+#             */
/*   Updated: 2025/05/06 18:20:21 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#define ENDOFMESSAGE '\n'

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
		write(STDERR_FILENO, "Usage: ./client <pid> <message>\n", 39);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_signal(pid, argv[2][i]);
		i++;
	}
	send_signal(pid, ENDOFMESSAGE);
	return (0);
}
