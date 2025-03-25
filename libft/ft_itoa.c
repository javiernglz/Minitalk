/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:46:29 by frnavarr          #+#    #+#             */
/*   Updated: 2024/10/04 13:07:35 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long int nb)
{
	unsigned int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			nlen;
	long int	nbr;

	nbr = n;
	nlen = ft_nbrlen(nbr);
	res = (char *)malloc((nlen + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[nlen--] = '\0';
	if (nbr == 0)
		res[0] = '0';
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		res[nlen--] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (res);
}

/* int	main(void)
{
	char	*res;

	res = ft_itoa(-2540);
	printf("The itoa number is: %s\n", res);
	return (0);
}
 */