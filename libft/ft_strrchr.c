/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:34:14 by frnavarr          #+#    #+#             */
/*   Updated: 2024/10/04 16:50:58 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

/* int	main(void)
{
	const char *str = "museo ruso!";
	char *res;

	res = ft_strrchr(str, 'u');

	if (res)
		printf("%s\n", res);
	else
		printf("Carácter no encontrado\n");
	return (0);
} */
