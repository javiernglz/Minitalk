/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:30:31 by frnavarr          #+#    #+#             */
/*   Updated: 2024/09/26 18:30:15 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	int	res;
	char		s1[] = "Hola";
	char		s2[] = "Holw";
	size_t	n;

	n = 3;
	res = ft_memcmp(s1, s2, n);

	if (res > 0)
		printf("s1 is longer");
	else if (res < 0)
		printf("s2 is longer");
	else
		printf("The strings are equal");
	return (0);
} */
