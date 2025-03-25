/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:00:47 by frnavarr          #+#    #+#             */
/*   Updated: 2024/09/27 12:54:38 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (0);
	ft_strlcpy(copy, s, len + 1);
	return (copy);
}

/* int	main(void)
{
	char	*str = "Telefonica";
	char	*copy = ft_strdup(str);

	if (copy)
	{
		printf("%s\n", copy);
		free(copy);
	}
	return (0);
}
 */