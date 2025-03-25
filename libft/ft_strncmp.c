/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:06:10 by frnavarr          #+#    #+#             */
/*   Updated: 2024/10/01 16:26:27 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	int	size;

	char	s1[] = "Hola";
	char	s2[] = "Holo";

	size = ft_strncmp(s1, s2, 4);

	if (size > 0)
		printf("s1 is longer");
	else if (size < 0)
		printf("s2 is longer");
	else
		printf("The strings are =.");
	return (0);
} */
