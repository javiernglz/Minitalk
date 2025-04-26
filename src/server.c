/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:14:24 by frnavarr          #+#    #+#             */
/*   Updated: 2025/04/26 14:13:35 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handle_signal(int signal)
{
	static int	bit_count;
	static int	character;

	bit_count = 0;
	character = 0;
	if (signal == SIGUSR1)
		character |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &character, 1);
		if (character == '\0')
			write(1, "\n", 1);
		bit_count = 0;
		character = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());

	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);

	while (1)
		pause();
}
