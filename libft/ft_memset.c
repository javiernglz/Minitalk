/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:08:34 by frnavarr          #+#    #+#             */
/*   Updated: 2024/10/09 12:55:09 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*ptr2;
	size_t			i;

	ptr2 = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		ptr2[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}

/* int main(void)
{
    char s[50] = "Hola, mundo!";
	
    ft_memset(s, '*', 5);
    printf("%s\n", s);
    return (0);
} */