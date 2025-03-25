/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:29:15 by frnavarr          #+#    #+#             */
/*   Updated: 2024/10/04 16:25:18 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	char	*ptr_aux;

	ptr_aux = (char *)s;
	while (len > 0)
	{
		*(ptr_aux++) = 0;
		len--;
	}
}
