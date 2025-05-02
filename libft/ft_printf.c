/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frnavarr <frnavarr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:54:07 by frnavarr          #+#    #+#             */
/*   Updated: 2025/05/02 15:48:14 by frnavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_conversion_filter(char c, va_list *args, int *count)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_putdir((void *)va_arg(*args, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_unsig_putnbr(va_arg(*args, unsigned int)));
	else if (c == 'x')
		ft_puthex((unsigned long long)va_arg(*args, unsigned int),
			count, false);
	else if (c == 'X')
		ft_puthex((unsigned long long)va_arg(*args, unsigned int), count, true);
	else if (c == '%')
		return (write(1, &c, 1));
	return (0);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;
	int		j;

	va_start(args, s);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != '%')
			j += ft_putchar(s[i]);
		else
		{
			i++;
			j += ft_conversion_filter(s[i], &args, &j);
		}
		i++;
	}
	va_end(args);
	return (j);
}
