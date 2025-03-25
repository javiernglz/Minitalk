/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:57:37 by frnavarr          #+#    #+#             */
/*   Updated: 2024/09/27 11:42:06 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] && (i + j) < len && big[i + j] == little[j])
				j++;
			if (little[j] == 0)
				return ((char *) &big[i]);
		}
		i++;
	}
	return (0);
}

/* int	main(void)
{
	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "Bar";
	char *ptr;
	size_t n;

	n = sizeof(largestring);
	ptr = ft_strnstr(largestring, smallstring, n);
	if (ptr)
		printf("%s\n", ptr);
	else
		printf("No encontrado.\n");
	return (0);
}
 */