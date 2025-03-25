/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:13:32 by frnavarr          #+#    #+#             */
/*   Updated: 2024/09/27 16:24:37 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	i = 0;
	subs = malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	while (i < len)
	{
		subs[i] = s[start];
		i++;
		start++;
	}
	subs[i] = '\0';
	return (subs);
}

/* int	main(void)
{
	char str[] = "Ya es otoño!!!!!";
	char *sub = ft_substr(str, 6, 6);

	printf("Subcadena:%s\n", sub);
	free(sub);
	return (0);
}
 */