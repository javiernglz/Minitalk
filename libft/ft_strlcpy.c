/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:14:36 by frnavarr          #+#    #+#             */
/*   Updated: 2024/10/01 16:12:13 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < size)
		ft_memcpy(dest, src, src_len + 1);
	else if (size != 0)
	{
		ft_memcpy(dest, src, size - 1);
		dest[size - 1] = 0;
	}
	return (src_len);
}

/* int	main(void)
{
	char src[] = "Quiero copiar la cadena";
	char dest[10];
	size_t	len;

	len = ft_strlcpy(dest, src, sizeof(dest));

	printf("Cadena copiada en el destino: %s\n", dest);
	printf("Longitud cadena inicial: %zu\n", len);
	printf("size del buffer destino: %zu\n", sizeof(dest));

	return (0);
} */
