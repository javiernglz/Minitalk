/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:59:27 by frnavarr          #+#    #+#             */
/*   Updated: 2024/09/26 18:29:36 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)&ptr[i]);
		i++;
	}
	return (0);
}

/* int main(void)
{
	const char str[] = "Hola, mundo!";
	char c = 'm';
	size_t n = sizeof(str);
	char *res = (char *)ft_memchr(str, c, n);

	if (res)
		printf("Carácter '%c' encontrado: %s\n", c, res);
	else
		printf("Carácter no encontrado.\n");
	return (0);
}
 */