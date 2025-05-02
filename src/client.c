/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:14:22 by frnavarr          #+#    #+#             */
/*   Updated: 2025/05/02 15:43:03 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

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
		usleep(500);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
		write(2, "Error\n", 6);
	else
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
		{
			send_signal(pid, argv[2][i]);
			i++;
		}
		send_signal(pid, '\0');
		ft_printf("\n %i message sent\n", i);
	}
}
