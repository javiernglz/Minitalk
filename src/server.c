/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:14:24 by frnavarr          #+#    #+#             */
/*   Updated: 2025/04/01 18:38:56 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	server(int signal)
{
	static int	i;
	static int	c;

	if (signal == SIGUSR1)
		c=c | (1 << i);
	i++;
}