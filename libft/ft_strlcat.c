/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:14:36 by frnavarr          #+#    #+#             */
/*   Updated: 2024/10/01 16:15:39 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dest_len >= size)
		dest_len = size;
	if (dest_len == size)
		return (size + src_len);
	if (src_len < size - dest_len)
		ft_memcpy(dest + dest_len, src, src_len + 1);
	else
	{
		ft_memcpy(dest + dest_len, src, size - dest_len - 1);
		dest[size - 1] = '\0';
	}
	return (dest_len + src_len);
}

/* int	main(void)
{
	char dest[15] = "Buenas ";
	char *src = "tardes";
	size_t conc;

	conc = ft_strlcat(dest, src, sizeof(dest));
	printf("%s\n", dest);
	printf("Longitud de la cadena concatenada: %zu\n", conc);
	return (0);
} */
