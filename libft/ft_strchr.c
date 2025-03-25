/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:22:42 by frnavarr          #+#    #+#             */
/*   Updated: 2024/10/01 16:21:13 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/* int	main(void)
{
	const char	*str;
	char		*res;

	str = "Hola malaga!"
	res = ft_strchr(str, 'a');
	if (res)
		printf("%s\n", res);
	else
		printf("Carácter no encontrado\n");
	return (0);
} */
